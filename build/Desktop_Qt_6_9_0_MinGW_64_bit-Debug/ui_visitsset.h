/********************************************************************************
** Form generated from reading UI file 'visitsset.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISITSSET_H
#define UI_VISITSSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_visitsSet
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *comboBox_doctor;
    QLabel *label;
    QLabel *label_4;
    QComboBox *comboBox_procedure;
    QComboBox *comboBox_patient;
    QLabel *label_3;
    QTimeEdit *timeEdit_visit;
    QPushButton *pushButton_accept;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *visitsSet)
    {
        if (visitsSet->objectName().isEmpty())
            visitsSet->setObjectName("visitsSet");
        visitsSet->resize(676, 340);
        gridLayout = new QGridLayout(visitsSet);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(visitsSet);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        comboBox_doctor = new QComboBox(visitsSet);
        comboBox_doctor->setObjectName("comboBox_doctor");

        gridLayout->addWidget(comboBox_doctor, 1, 1, 1, 1);

        label = new QLabel(visitsSet);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(visitsSet);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        comboBox_procedure = new QComboBox(visitsSet);
        comboBox_procedure->setObjectName("comboBox_procedure");

        gridLayout->addWidget(comboBox_procedure, 1, 2, 1, 1);

        comboBox_patient = new QComboBox(visitsSet);
        comboBox_patient->setObjectName("comboBox_patient");

        gridLayout->addWidget(comboBox_patient, 1, 0, 1, 1);

        label_3 = new QLabel(visitsSet);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        timeEdit_visit = new QTimeEdit(visitsSet);
        timeEdit_visit->setObjectName("timeEdit_visit");

        gridLayout->addWidget(timeEdit_visit, 1, 3, 1, 1);

        pushButton_accept = new QPushButton(visitsSet);
        pushButton_accept->setObjectName("pushButton_accept");

        gridLayout->addWidget(pushButton_accept, 2, 1, 1, 1);

        pushButton_cancel = new QPushButton(visitsSet);
        pushButton_cancel->setObjectName("pushButton_cancel");

        gridLayout->addWidget(pushButton_cancel, 2, 2, 1, 1);


        retranslateUi(visitsSet);

        QMetaObject::connectSlotsByName(visitsSet);
    } // setupUi

    void retranslateUi(QDialog *visitsSet)
    {
        visitsSet->setWindowTitle(QCoreApplication::translate("visitsSet", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("visitsSet", "Lekarz", nullptr));
        label->setText(QCoreApplication::translate("visitsSet", "Pacjent", nullptr));
        label_4->setText(QCoreApplication::translate("visitsSet", "Godzina", nullptr));
        label_3->setText(QCoreApplication::translate("visitsSet", "Zabieg", nullptr));
        pushButton_accept->setText(QCoreApplication::translate("visitsSet", "Zatwierd\305\272", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("visitsSet", "Anuluj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class visitsSet: public Ui_visitsSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISITSSET_H
