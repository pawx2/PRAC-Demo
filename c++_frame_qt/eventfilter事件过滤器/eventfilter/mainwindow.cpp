#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QEvent>
#include<QString>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Step1 为label安装事件过滤器 安装者为MainWindow
    ui->label->installEventFilter(this);
    //Step2 重写eventfilter

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Step2 重写eventfilter
bool MainWindow::eventFilter(QObject* obj, QEvent* ev)
{
    if(obj == ui->label && ev->type() == QEvent::MouseButtonPress)
    {
        QString str = QString("通过过滤器进行拦截！");
        qDebug() << str;
        return true;
    }
    return QWidget::eventFilter(obj, ev);
}
