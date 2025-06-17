#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "databasemanager.h"
#include "visits.h"
#include <QDebug>


class DataBaseManager;

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_login_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_visits_clicked();

    void on_pushButton_patList_clicked();

    void on_pushButton_mag_clicked();

private:
    Ui::MainWindow *ui;
    DataBaseManager *m_dbManager;
    visits *visitsDial;
};
#endif // MAINWINDOW_H
