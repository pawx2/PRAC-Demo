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
    /*绘图高级设置*/
    QPainter painter(this);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    //设置 抗锯齿能力 绘制效率较低
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(QPoint(200, 100), 50, 50);
    //图形重叠 移动painter进行绘制
    painter.drawEllipse(QPoint(300, 100), 50, 50);
    //保存画家状态
    painter.save();
    painter.translate(200, 0);
    painter.drawEllipse(QPoint(300, 100), 50, 50);
    //还原画家状态 重新绘画，发现图形被已有图形遮挡了
    painter.restore();
    painter.drawEllipse(QPoint(300, 100), 50, 50);
}
