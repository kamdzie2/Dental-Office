#ifndef VISITSCHECKDATE_H
#define VISITSCHECKDATE_H

#include <QDialog>
#include <QDate>
#include "databasemanager.h"
#include "visitsset.h"

class DataBaseManager;
class QSqlQueryModel;

QT_BEGIN_NAMESPACE
namespace Ui { class VisitsCheckDate; }
QT_END_NAMESPACE

class VisitsCheckDate : public QDialog
{
    Q_OBJECT

public:
    explicit VisitsCheckDate(const QDate &date, DataBaseManager *dbManager, QWidget *parent = nullptr);
    ~VisitsCheckDate();

private slots:
    void on_pushButton_setVisit_clicked();

    void on_pushButton_editVisit_clicked();

    void on_pushButton_delVisit_clicked();

private:
    Ui::VisitsCheckDate *ui;
    QDate m_selectedDate;
    QSqlQueryModel *m_appointmentsModel;
    DataBaseManager *m_dbManager;

    void loadAppointmentsForDate(const QDate &date);

};

#endif // VISITSCHECKDATE_H
