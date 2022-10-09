#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QPainter>
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //绑定按钮进行移动
    connect(ui->pushButton, &QPushButton::clicked, [=]()->void{
        posX += 20;
        //手动调用绘图事件进行更新
        update();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* ev)
{
    QPainter painter = QPainter(this);
    //超出屏幕尺寸从0开始
    if(this->width() < posX) posX = 0;
    //利用画家绘制图片
    painter.drawPixmap(posX, 100, QPixmap(":/img/Image/Luffy.png"));
}
