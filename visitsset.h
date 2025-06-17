#ifndef VISITSSET_H
#define VISITSSET_H

#include <QDialog>
#include <QDate>
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include <QPushButton>

class DataBaseManager;
class QSqlDatabase;

QT_BEGIN_NAMESPACE
namespace Ui { class visitsSet; }
QT_END_NAMESPACE

class visitsSet : public QDialog
{
    Q_OBJECT

public:
    explicit visitsSet(const QDate &date, DataBaseManager *dbManager, QWidget *parent = nullptr);
    ~visitsSet();

private slots:
    void on_accept_button_clicked();

private:

    void populatePatientComboBox();
    void populateDoctorComboBox();
    void populateProcedureComboBox();

    Ui::visitsSet *ui;
    QDate m_visitDate;
    DataBaseManager *m_dbManager;
};

#endif // VISITSSET_H
