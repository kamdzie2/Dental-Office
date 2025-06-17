#ifndef VISITS_H
#define VISITS_H


#include <QDialog>
#include <QMessageBox>
#include "visitscheckdate.h"
#include "databasemanager.h"

class DataBaseManager;
namespace Ui {
class visits;
}

class visits : public QDialog
{
    Q_OBJECT

public:
    explicit visits(DataBaseManager *dbManager, QWidget *parent = nullptr);
    ~visits();

private slots:
    void on_calendarWidget_dateClicked(const QDate &date);

private:
    Ui::visits *ui;

    VisitsCheckDate *visitscheckdate;
    DataBaseManager *m_dbManager;
};

#endif // VISITS_H
