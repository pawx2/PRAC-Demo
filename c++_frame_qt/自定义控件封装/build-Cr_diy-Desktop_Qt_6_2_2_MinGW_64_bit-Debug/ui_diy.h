/********************************************************************************
** Form generated from reading UI file 'diy.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIY_H
#define UI_DIY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_diy
{
public:
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *diy)
    {
        if (diy->objectName().isEmpty())
            diy->setObjectName(QString::fromUtf8("diy"));
        diy->resize(227, 50);
        horizontalLayout = new QHBoxLayout(diy);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spinBox = new QSpinBox(diy);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);

        horizontalSlider = new QSlider(diy);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);


        retranslateUi(diy);

        QMetaObject::connectSlotsByName(diy);
    } // setupUi

    void retranslateUi(QWidget *diy)
    {
        diy->setWindowTitle(QCoreApplication::translate("diy", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class diy: public Ui_diy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIY_H
