#include "visits.h"
#include "ui_visits.h"


visits::visits(DataBaseManager *dbManager, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::visits),
    m_dbManager(dbManager)
{
    ui->setupUi(this);
     connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &visits::on_calendarWidget_dateClicked);
}

visits::~visits()
{
    delete ui;
}

void visits::on_calendarWidget_dateClicked(const QDate &date)
{
    if (!m_dbManager || !m_dbManager->isOpen()) {
        QMessageBox::critical(this, "Błąd", "Brak aktywnego połączenia z bazą danych!");
        return;
    }

    VisitsCheckDate *checkDateDialog = new VisitsCheckDate(date, m_dbManager, this);
    checkDateDialog->exec();
    delete checkDateDialog;
}

