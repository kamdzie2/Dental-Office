/********************************************************************************
** Form generated from reading UI file 'visits.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISITS_H
#define UI_VISITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>

QT_BEGIN_NAMESPACE

class Ui_visits
{
public:
    QGridLayout *gridLayout;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *visits)
    {
        if (visits->objectName().isEmpty())
            visits->setObjectName("visits");
        visits->resize(868, 478);
        gridLayout = new QGridLayout(visits);
        gridLayout->setObjectName("gridLayout");
        calendarWidget = new QCalendarWidget(visits);
        calendarWidget->setObjectName("calendarWidget");

        gridLayout->addWidget(calendarWidget, 0, 0, 1, 1);


        retranslateUi(visits);

        QMetaObject::connectSlotsByName(visits);
    } // setupUi

    void retranslateUi(QDialog *visits)
    {
        visits->setWindowTitle(QCoreApplication::translate("visits", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class visits: public Ui_visits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISITS_H
