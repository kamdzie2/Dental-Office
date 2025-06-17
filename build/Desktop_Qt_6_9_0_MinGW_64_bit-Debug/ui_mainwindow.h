/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_logout;
    QPushButton *pushButton_patList;
    QPushButton *pushButton_visits;
    QPushButton *pushButton_mag;
    QPushButton *pushButton_login;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(948, 412);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        pushButton_logout = new QPushButton(centralwidget);
        pushButton_logout->setObjectName("pushButton_logout");

        gridLayout_2->addWidget(pushButton_logout, 5, 1, 1, 1);

        pushButton_patList = new QPushButton(centralwidget);
        pushButton_patList->setObjectName("pushButton_patList");

        gridLayout_2->addWidget(pushButton_patList, 1, 0, 1, 1);

        pushButton_visits = new QPushButton(centralwidget);
        pushButton_visits->setObjectName("pushButton_visits");

        gridLayout_2->addWidget(pushButton_visits, 0, 0, 1, 1);

        pushButton_mag = new QPushButton(centralwidget);
        pushButton_mag->setObjectName("pushButton_mag");

        gridLayout_2->addWidget(pushButton_mag, 2, 0, 1, 1);

        pushButton_login = new QPushButton(centralwidget);
        pushButton_login->setObjectName("pushButton_login");

        gridLayout_2->addWidget(pushButton_login, 4, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 948, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_logout->setText(QCoreApplication::translate("MainWindow", "Wyloguj", nullptr));
        pushButton_patList->setText(QCoreApplication::translate("MainWindow", "Lista pacjent\303\263w", nullptr));
        pushButton_visits->setText(QCoreApplication::translate("MainWindow", "Um\303\263w wizyte", nullptr));
        pushButton_mag->setText(QCoreApplication::translate("MainWindow", "Magazyn", nullptr));
        pushButton_login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
