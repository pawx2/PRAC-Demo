#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QPushButton>
#include<QStackedWidget>
#include<QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*Stacked Widget*/
    //设置Stacked Widget初始页面
    ui->stackedWidget->setCurrentIndex(0);
    //为Stacked Widget不同页面绑定不同按钮
    //为Scroll Area页面绑定按钮
    connect(ui->btn_0, &QPushButton::clicked, ui->stackedWidget, [=]()->void{
        ui->stackedWidget->setCurrentIndex(0);
    });
    //为Tool Box页面绑定按钮
    connect(ui->btn_1, &QPushButton::clicked, ui->stackedWidget, [=]()->void{
        ui->stackedWidget->setCurrentIndex(1);
    });
    //为Tab Widget页面绑定按钮
    connect(ui->btn_2, &QPushButton::clicked, ui->stackedWidget, [=]()->void{
        ui->stackedWidget->setCurrentIndex(2);
    });

    /*ComboBox*/
    //为ComboBox添加选项
    ui->comboBox->addItem("汽车");
    ui->comboBox->addItem("高铁");
    ui->comboBox->addItem("飞机");

    //为特定选中按钮设置信号-槽
    connect(ui->btn_choose, &QPushButton::clicked, ui->comboBox, [=]()->void{
        ui->comboBox->setCurrentIndex(2);
    });

    /*Label*/
    //设置标签显示静态图片
    ui->label->setPixmap(QPixmap(":/img/Image/up.png"));
    //设置标签显示gif动态图片
    QMovie* gif = new QMovie(":/img/Image/mario.gif");
    ui->label_2->setMovie(gif);
    //播放动图
    gif->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

