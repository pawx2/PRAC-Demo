/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
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
    QLabel *timer1;
    QLabel *timer2;
    QLabel *timer3;
    QPushButton *btn_start;
    QPushButton *btn_pause;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        timer1 = new QLabel(centralwidget);
        timer1->setObjectName(QString::fromUtf8("timer1"));
        timer1->setGeometry(QRect(60, 170, 69, 20));
        timer2 = new QLabel(centralwidget);
        timer2->setObjectName(QString::fromUtf8("timer2"));
        timer2->setGeometry(QRect(70, 270, 69, 20));
        timer3 = new QLabel(centralwidget);
        timer3->setObjectName(QString::fromUtf8("timer3"));
        timer3->setGeometry(QRect(70, 340, 69, 20));
        btn_start = new QPushButton(centralwidget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(80, 420, 92, 29));
        btn_pause = new QPushButton(centralwidget);
        btn_pause->setObjectName(QString::fromUtf8("btn_pause"));
        btn_pause->setGeometry(QRect(80, 470, 92, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        timer1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        timer2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        timer3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btn_start->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250", nullptr));
        btn_pause->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
