#ifndef PATIENTSLIST_H
#define PATIENTSLIST_H

#include <QDialog>
#include "databasemanager.h"

class DataBaseManager;
class QSqlTableModel;

namespace Ui {
class PatientsList;
}

class PatientsList : public QDialog
{
    Q_OBJECT

public:
    explicit PatientsList(DataBaseManager *dbManager,QWidget *parent = nullptr);
    ~PatientsList();

private slots:
    void on_editPatient_pb_clicked();

    void on_deletePatient_pb_clicked();

private:
    Ui::PatientsList *ui;
    DataBaseManager *m_dbManager;
    QSqlTableModel *m_patientsList;

    void setupModel();
};

#endif // PATIENTSLIST_H
