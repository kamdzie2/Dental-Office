#include "visitscheckdate.h"
#include "ui_visitscheckdate.h"

VisitsCheckDate::VisitsCheckDate(const QDate &date, DataBaseManager *dbManager, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VisitsCheckDate),
    m_selectedDate(date),
    m_dbManager(dbManager)
{
    ui->setupUi(this);

    setWindowTitle(QString("Wizyty w dniu %1").arg(m_selectedDate.toString("d MMMM yyyr.")));

    m_appointmentsModel = new QSqlQueryModel(this);

    ui->tableView_visits->setModel(m_appointmentsModel);

    loadAppointmentsForDate(m_selectedDate);
}

VisitsCheckDate::~VisitsCheckDate()
{
    delete ui;
}

void VisitsCheckDate::loadAppointmentsForDate(const QDate &date)
{
    if (!m_dbManager || !m_dbManager->isOpen()) {
        QMessageBox::critical(this, "Błąd Krytyczny", "Połączenie z bazą danych nie jest aktywne lub manager nie istnieje.");
        return;
    }

    QSqlDatabase db = m_dbManager->getDatabase();

    QString queryString = R"(
        SELECT
            p.procedure_id,
            TIME(p.procedure_date) AS 'Godzina',
            CONCAT(pa.Name, ' ', pa.Surname) AS 'Pacjent',
            pa.PESEL,
            pa.phone_number AS 'Numer telefonu',
            CONCAT(d.first_name, ' ', d.last_name) AS 'Lekarz',
            pt.name AS 'Typ zabiegu',
            p.status AS 'Status'
        FROM
            procedures p
        INNER JOIN
            patients pa ON p.patient_id = pa.id
        INNER JOIN
            doctors d ON p.doctor_id = d.doctor_id
        INNER JOIN
            procedure_types pt ON p.procedure_type_id = pt.procedure_type_id
        WHERE
            DATE(p.procedure_date) = :wybrana_data
        ORDER BY
            p.procedure_date
    )";

    QSqlQuery query(db);
    query.prepare(queryString);
    query.bindValue(":wybrana_data", date);

    if (query.exec()) {
        qDebug() << "Pomyślnie pobrano wizyty dla daty:" << date.toString("yyyy-MM-dd");

        m_appointmentsModel->setQuery(query);

        if (m_appointmentsModel->lastError().isValid()) {
            qDebug() << "Błąd modelu po ustawieniu zapytania:" << m_appointmentsModel->lastError().text();
            QMessageBox::critical(this, "Błąd Modelu Danych", "Wystąpił błąd podczas przetwarzania wyników zapytania: " + m_appointmentsModel->lastError().text());
        }
        ui->tableView_visits->hideColumn(0);
        ui->tableView_visits->resizeColumnsToContents();

    } else {
        qDebug() << "Błąd wykonania zapytania o wizyty:" << query.lastError().text();
        QMessageBox::critical(this, "Błąd Zapytania SQL", "Nie udało się pobrać danych o wizytach dla wybranego dnia.");
    }
}

void VisitsCheckDate::on_pushButton_setVisit_clicked()
{

    visitsSet *setDialog = new visitsSet(m_selectedDate, m_dbManager, this);

    if (setDialog->exec() == QDialog::Accepted) {

        qDebug() << "Wizyta została dodana. Odświeżam widok tabeli...";
        loadAppointmentsForDate(m_selectedDate);
    } else {
        qDebug() << "Proces umawiania wizyty został anulowany.";
    }

    delete setDialog;
}


void VisitsCheckDate::on_pushButton_editVisit_clicked()
{

}


void VisitsCheckDate::on_pushButton_delVisit_clicked()
{
    QItemSelectionModel *selectionModel = ui->tableView_visits->selectionModel();
    if (!selectionModel->hasSelection()) {
        QMessageBox::information(this, "Brak zaznaczenia", "Proszę najpierw zaznaczyć wizytę, którą chcesz usunąć.");
        return;
    }

    QModelIndex selectedIndex = selectionModel->currentIndex();
    int procedureId = m_appointmentsModel->record(selectedIndex.row()).value("procedure_id").toInt();
    if (procedureId <= 0) {
        QMessageBox::critical(this, "Błąd", "Nie udało się zidentyfikować wybranej wizyty.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Potwierdzenie usunięcia",
                                  QString("Czy na pewno chcesz usunąć wybraną wizytę (ID: %1)? Tej operacji nie można cofnąć.").arg(procedureId),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return;
    }

    if (!m_dbManager->isOpen()) {
        QMessageBox::critical(this, "Błąd", "Brak połączenia z bazą danych!");
        return;
    }

    QSqlQuery deleteQuery(m_dbManager->getDatabase());
    deleteQuery.prepare("DELETE FROM procedures WHERE procedure_id = :id");
    deleteQuery.bindValue(":id", procedureId);

    if (deleteQuery.exec()) {
        QMessageBox::information(this, "Sukces", "Wizyta została pomyślnie usunięta.");
        loadAppointmentsForDate(m_selectedDate);
    } else {
        QMessageBox::critical(this, "Błąd bazy danych", "Nie udało się usunąć wizyty.\nBłąd: " + deleteQuery.lastError().text());
    }

}

