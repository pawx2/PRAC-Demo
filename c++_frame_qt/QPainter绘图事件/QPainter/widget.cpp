#include "widget.h"
#include "ui_widget.h"
#include<QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent* )
{
    //实例化一个Painter对象 传入device指定绘图设备为当前窗口
    QPainter painter(this);

    //设置画笔颜色
    QPen pen(QColor(255, 0, 0));
    //设置画笔宽度
    pen.setWidth(3);
    //设置画笔风格
    pen.setStyle(Qt::DashLine);
    //将pen与painter绑定
    painter.setPen(pen);

    //设置画刷
    QBrush brush(Qt::cyan);             //设置颜色
    brush.setStyle(Qt::Dense6Pattern);  //设置风格
    //将brush与painter绑定
    painter.setBrush(brush);

    //绘制一条直线
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
    //绘制一个圆/椭圆
    painter.drawEllipse(QPoint(100, 100), 80, 80);
    //绘制一个矩形
    painter.drawRect(100, 100, 100, 100);
    //绘制文字
    painter.drawText(QRect(200, 200, 50, 50), "呵呵呵");
}
