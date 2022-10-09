#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"diy.h"

#include<QPushButton>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //绑定按钮 按下按钮获取当前的值
    connect(ui->btn_getcur, &QPushButton::clicked, ui->widget, [=]()->void{
       qDebug() << ui->widget->getValue();
    });
    //绑定按钮 按下按钮将当前的值设置为一半
    connect(ui->btn_sethalf, &QPushButton::clicked, ui->widget, [=]()->void{
        ui->widget->setValue(49);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

