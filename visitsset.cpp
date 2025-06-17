#include "visitsset.h"
#include "ui_visitsset.h"

visitsSet::visitsSet(const QDate &date, DataBaseManager *dbManager, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::visitsSet),
    m_visitDate(date),
    m_dbManager(dbManager)
{
    ui->setupUi(this);
    setWindowTitle(QString("Umów nową wizytę na dzień %1").arg(m_visitDate.toString("d.MM.yyyy")));

    connect(ui->pushButton_accept, &QPushButton::clicked, this, &::visitsSet::on_accept_button_clicked);

    connect(ui->pushButton_cancel, &QPushButton::clicked, this, &QDialog::reject);

    populatePatientComboBox();
    populateDoctorComboBox();
    populateProcedureComboBox();
}

visitsSet::~visitsSet()
{
    delete ui;
}

void visitsSet::on_accept_button_clicked()
{
    int patientId = ui->comboBox_patient->currentData().toInt();
    int doctorId = ui->comboBox_doctor->currentData().toInt();
    int procedureTypeId = ui->comboBox_procedure->currentData().toInt();

    if (patientId == 0 || doctorId == 0 || procedureTypeId == 0) {
        QMessageBox::warning(this, "Brak danych", "Proszę wybrać pacjenta, lekarza i typ zabiegu.");
        return;
    }

    double procedureCost = 0.0;
    QSqlQuery priceQuery(m_dbManager->getDatabase());
    priceQuery.prepare("SELECT default_price FROM procedure_types WHERE procedure_type_id = :id");
    priceQuery.bindValue(":id", procedureTypeId);

    if (priceQuery.exec()) {
        if (priceQuery.next()) {
            procedureCost = priceQuery.value(0).toDouble();
            qDebug() << "Pobrano cenę dla zabiegu o ID" << procedureTypeId << ":" << procedureCost;
        } else {
            QMessageBox::warning(this, "Błąd danych", "Nie znaleziono ceny dla wybranego zabiegu.");
            return;
        }
    } else {
        QMessageBox::critical(this, "Błąd bazy danych", "Nie udało się pobrać ceny zabiegu.\nBłąd: " + priceQuery.lastError().text());
        return;
    }

    QTime visitTime = ui->timeEdit_visit->time();
    QDateTime visitDateTime(m_visitDate, visitTime);

    QSqlQuery insertQuery(m_dbManager->getDatabase());
    insertQuery.prepare(
        "INSERT INTO procedures (patient_id, doctor_id, procedure_type_id, procedure_date, cost, status) "
        "VALUES (:patient, :doctor, :procedure, :datetime, :cost, 'Scheduled')" // Dodany placeholder
        );

    insertQuery.bindValue(":patient", patientId);
    insertQuery.bindValue(":doctor", doctorId);
    insertQuery.bindValue(":procedure", procedureTypeId);
    insertQuery.bindValue(":datetime", visitDateTime);
    insertQuery.bindValue(":cost", procedureCost); // Powiąż pobraną cenę z placeholderem
    insertQuery.bindValue(":status", "Scheduled"); // Status można też dodać tutaj, jeśli nie ma wartości domyślnej w bazie

    if (insertQuery.exec()) {
        QMessageBox::information(this, "Sukces", "Nowa wizyta została pomyślnie umówiona.");
        accept();
    } else {
        QMessageBox::critical(this, "Błąd bazy danych", "Nie udało się zapisać wizyty.\nBłąd: " + insertQuery.lastError().text());
    }
}

void visitsSet::populatePatientComboBox()
{
    QSqlQuery query(m_dbManager->getDatabase());
    if (query.exec("SELECT id, Name, Surname FROM patients ORDER BY Surname, Name")) {
        while (query.next()) {
            QString displayText = QString("%1 %2").arg(query.value("Name").toString(), query.value("Surname").toString());
            QVariant id = query.value("id");
            ui->comboBox_patient->addItem(displayText, id);
        }
    } else {
        qDebug() << "Błąd pobierania listy pacjentów:" << query.lastError().text();
    }
}

void visitsSet::populateDoctorComboBox()
{
    QSqlQuery query(m_dbManager->getDatabase());
    if (query.exec("SELECT doctor_id, first_name, last_name FROM doctors ORDER BY last_name, first_name")) {
        while (query.next()) {
            QString displayText = QString("%1 %2").arg(query.value("first_name").toString(), query.value("last_name").toString());
            QVariant id = query.value("doctor_id");
            ui->comboBox_doctor->addItem(displayText, id);
        }
    } else {
        qDebug() << "Błąd pobierania listy lekarzy:" << query.lastError().text();
    }
}

void visitsSet::populateProcedureComboBox()
{
    QSqlQuery query(m_dbManager->getDatabase());
    if (query.exec("SELECT procedure_type_id, name FROM procedure_types WHERE is_active = 1 ORDER BY name")) {
        while (query.next()) {
            QString displayText = query.value("name").toString();
            QVariant id = query.value("procedure_type_id");
            ui->comboBox_procedure->addItem(displayText, id);
        }
    } else {
        qDebug() << "Błąd pobierania listy zabiegów:" << query.lastError().text();
    }
}
