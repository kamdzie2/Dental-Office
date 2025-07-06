#include "patientslist.h"
#include "ui_patientslist.h"

PatientsList::PatientsList(DataBaseManager *dbManager,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PatientsList),
    m_dbManager(dbManager)
{
    ui->setupUi(this);

    m_patientsList = new QSqlTableModel(this, m_dbManager->getDatabase());

    ui->tableView_patList->setModel(m_patientsList);

    setupModel();
}

void PatientsList::setupModel()
{
    m_patientsList->setTable("patients");
    m_patientsList->setEditStrategy(QSqlTableModel::OnManualSubmit);

    m_patientsList->setHeaderData(m_patientsList->fieldIndex("Name"), Qt::Horizontal, "Imię");
    m_patientsList->setHeaderData(m_patientsList->fieldIndex("Surname"), Qt::Horizontal, "Nazwisko");
    m_patientsList->setHeaderData(m_patientsList->fieldIndex("birth_date"), Qt::Horizontal, "Data urodzenia");
    m_patientsList->setHeaderData(m_patientsList->fieldIndex("PESEL"), Qt::Horizontal, "PESEL");
    m_patientsList->setHeaderData(m_patientsList->fieldIndex("phone_number"), Qt::Horizontal, "Numer telefonu");
    m_patientsList->setHeaderData(m_patientsList->fieldIndex("Address"), Qt::Horizontal, "Adres");


    if (!m_patientsList->select()) {
        qDebug() << "Błąd ładowania danych do modelu:" << m_patientsList->lastError().text();
        QMessageBox::critical(this, "Błąd ładowania", "Nie udało się załadować danych pacjentów.");
    }

    ui->tableView_patList->hideColumn(m_patientsList->fieldIndex("id"));
    ui->tableView_patList->resizeColumnsToContents();
}


PatientsList::~PatientsList()
{
    delete ui;
}

void PatientsList::on_editPatient_pb_clicked()
{
    if (m_patientsList->submitAll()) {
        qDebug() << "Zmiany zostały pomyślnie zapisane w bazie danych.";
        QMessageBox::information(this, "Sukces", "Wszystkie zmiany zostały zapisane.");
    } else {
        qDebug() << "Błąd zapisu zmian:" << m_patientsList->lastError().text();
        QMessageBox::warning(this, "Błąd zapisu",
                             "Nie udało się zapisać zmian w bazie danych.\n"
                             "Błąd: " + m_patientsList->lastError().text());
        m_patientsList->revertAll();
    }
}



void PatientsList::on_deletePatient_pb_clicked()
{
    QItemSelectionModel *selectionModel = ui->tableView_patList->selectionModel();
    if (!selectionModel->hasSelection()) {
        QMessageBox::information(this, "Brak zaznaczenia", "Proszę najpierw zaznaczyć pacjenta, którego chcesz usunąć.");
        return;
    }

    QModelIndex selectedIndex = selectionModel->currentIndex();
    int row = selectedIndex.row();

    int patientId = m_patientsList->record(row).value("id").toInt();
    QString patientName = m_patientsList->record(row).value("Name").toString();
    QString patientSurname = m_patientsList->record(row).value("Surname").toString();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Potwierdzenie usunięcia",
                                  QString("Czy na pewno chcesz usunąć pacjenta: %1 %2 (ID: %3)?\n\nUsunięcie pacjenta może spowodować usunięcie powiązanych z nim wizyt, jeśli baza danych ma ustawione odpowiednie więzy integralności (CASCADE).")
                                      .arg(patientName, patientSurname).arg(patientId),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return;
    }

    m_patientsList->removeRow(row);

    if (m_patientsList->submitAll()) {
        QMessageBox::information(this, "Sukces", "Pacjent został usunięty z bazy danych.");
    } else {
        QMessageBox::critical(this, "Błąd bazy danych", "Nie udało się usunąć pacjenta.\nBłąd: " + m_patientsList->lastError().text());
        m_patientsList->revertAll();
    }
}

