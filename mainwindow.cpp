#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_dbManager(nullptr)
{
    ui->setupUi(this);

    m_dbManager = new DataBaseManager(this);

    m_dbManager->setConnectionPar("QMYSQL","localhost","dentist", "root","", 3306);

    if (m_dbManager->openConnection())
    {
        qDebug() << "Połączenie z bazą danych w MainWindow udane";
        ui->statusbar->showMessage("Pomyślnie połączono z bazą danych.", 5000);

        QSqlQuery query(m_dbManager->getDatabase());
        if (query.exec("SELECT VERSION();"))
        {
            if (query.next())
            {
                qDebug() << "Wersja serwera:" << query.value(0).toString();
            }
        } else {
            QMessageBox::critical(this, "Błąd zapytania", "Nie udało się wykonać zapytania: " + query.lastError().text());
        }

    } else {
        qDebug() << "Połączenie z bazą danych w MainWindow NIE udane.";
        QMessageBox::critical(this, "Błąd połączenia", "Nie udało się połączyć z bazą danych: " + m_dbManager->getLastError().text());
        ui->statusbar->showMessage("Błąd połączenia z bazą danych!", 5000);
    }
}

MainWindow::~MainWindow()
{
    delete m_dbManager;
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{

}


void MainWindow::on_pushButton_logout_clicked()
{

}


void MainWindow::on_pushButton_visits_clicked()
{
    visitsDial = new visits(m_dbManager,this);
    visitsDial -> show();
}


void MainWindow::on_pushButton_patList_clicked()
{
    patientsList = new PatientsList(m_dbManager,this);
    patientsList -> show();
}


void MainWindow::on_pushButton_mag_clicked()
{

}

