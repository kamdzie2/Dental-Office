/********************************************************************************
** Form generated from reading UI file 'visitscheckdate.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISITSCHECKDATE_H
#define UI_VISITSCHECKDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_VisitsCheckDate
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView_visits;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_editVisit;
    QPushButton *pushButton_setVisit;
    QPushButton *pushButton_delVisit;

    void setupUi(QDialog *VisitsCheckDate)
    {
        if (VisitsCheckDate->objectName().isEmpty())
            VisitsCheckDate->setObjectName("VisitsCheckDate");
        VisitsCheckDate->resize(760, 339);
        gridLayout = new QGridLayout(VisitsCheckDate);
        gridLayout->setObjectName("gridLayout");
        tableView_visits = new QTableView(VisitsCheckDate);
        tableView_visits->setObjectName("tableView_visits");

        gridLayout->addWidget(tableView_visits, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        pushButton_editVisit = new QPushButton(VisitsCheckDate);
        pushButton_editVisit->setObjectName("pushButton_editVisit");

        gridLayout_2->addWidget(pushButton_editVisit, 1, 0, 1, 1);

        pushButton_setVisit = new QPushButton(VisitsCheckDate);
        pushButton_setVisit->setObjectName("pushButton_setVisit");

        gridLayout_2->addWidget(pushButton_setVisit, 0, 0, 1, 1);

        pushButton_delVisit = new QPushButton(VisitsCheckDate);
        pushButton_delVisit->setObjectName("pushButton_delVisit");

        gridLayout_2->addWidget(pushButton_delVisit, 2, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 1, 1, 1);


        retranslateUi(VisitsCheckDate);

        QMetaObject::connectSlotsByName(VisitsCheckDate);
    } // setupUi

    void retranslateUi(QDialog *VisitsCheckDate)
    {
        VisitsCheckDate->setWindowTitle(QCoreApplication::translate("VisitsCheckDate", "Dialog", nullptr));
        pushButton_editVisit->setText(QCoreApplication::translate("VisitsCheckDate", "Edytuj wizyt\304\231", nullptr));
        pushButton_setVisit->setText(QCoreApplication::translate("VisitsCheckDate", "Um\303\263w wizyt\304\231", nullptr));
        pushButton_delVisit->setText(QCoreApplication::translate("VisitsCheckDate", "Usu\305\204 wizyt\304\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VisitsCheckDate: public Ui_VisitsCheckDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISITSCHECKDATE_H
