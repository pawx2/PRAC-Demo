#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QLabel>
#include<QTimer>
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*定时器-利用事件触发*/
    //分别启动一个 1s为单位的计时器 2s为单位的计时器
    //每隔设定的单位时间会调用一次timerEvent函数
    timer1_id = startTimer(1000);   //参数 时间间隔 毫秒为单位，返回整数类型-计时器id地址传入到timerEvent函数触发事件
    timer2_id = startTimer(2000);

    /*定时器-利用控件*/
    QTimer* timer = new QTimer(this);
    timer->start(500);  //每隔500毫秒发送一个信号
    static int time3 = 1;
    connect(timer, &QTimer::timeout, [=]()->void{
        ui->timer3->setText(QString::number(time3++));
    });

    //绑定启动/暂停按钮
    connect(ui->btn_start, &QPushButton::clicked, timer, [=]()->void{
        timer->start(500);
    });
    connect(ui->btn_pause, &QPushButton::clicked, timer, [=]()->void{
        timer->stop();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent* ev)
{
    if(ev->timerId() == timer1_id)
    {
        static int time1 = 1;   //静态变量，仅初始化一次
        ui->timer1->setText(QString::number(time1++));

    }

    if(ev->timerId() == timer2_id)
    {
        static int time2 = 1;
        ui->timer2->setText(QString::number(time2++));
    }
}
