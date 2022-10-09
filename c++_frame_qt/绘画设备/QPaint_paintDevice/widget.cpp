#include "widget.h"
#include "ui_widget.h"

#include<QPixmap>
#include<QPainter>
#include<QPicture>

//#define USE_QPIXMAP
//#define USE_QIMAGE
#define USE_QPICTURE

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

#ifdef USE_QPIXMAP
    /*绘图设备QPixmap*/
    //Pixmap绘图设备 设定宽度高度
    //专门为平台制作了显示优化
    QPixmap pix(200, 200);
    //填充颜色
    pix.fill(Qt::yellow);
    //创建画家
    QPainter painter(&pix);
    painter.setPen(QPen(Qt::red));
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    //保存绘图结果
    pix.save("D:\\pix.png");
#endif

#ifdef USE_QIMAGE
    /*绘图设备QImage*/
    //可以对像素进行访问
    QImage img(200, 200, QImage::Format_RGB32);
    img.fill(Qt::blue);
    //创建画家
    QPainter painter(&img);
    painter.setPen(QPen(Qt::yellow));
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    //保存绘图结果
    img.save("D:\\img.png");
#endif

#ifdef USE_QPICTURE
    /*绘图设备QPicture*/
    //用于记录和重现绘图指令
    QPicture pic;
    QPainter painter;
    //设置画家的绘图设备 开始向pic上绘图
    painter.begin(&pic);
    painter.setPen(QPen(Qt::cyan));
    painter.drawEllipse(QPoint(150, 150), 100, 100);
    painter.end();  //绘图结束
    //保存绘图结果
    pic.save("D:\\pic.zt");
#endif
}

Widget::~Widget()
{
    delete ui;
}

//绘图事件
void Widget::paintEvent(QPaintEvent* ev)
{
#ifdef USE_QIMAGE
    //利用QImage 对像素进行修改
    QImage img;
    img.load(":/img/Image/Luffy.png");
    //新建画家
    QPainter painter(this);
    //绘制前修改像素点
    for(int r = 0; r < 100; r++)
    {
        for(int c = 0; c < 100; c++)
        {
            //像素点类型
            QRgb value = qRgb(0, 255, 0);
            img.setPixel(r, c, value);
        }
    }
    //进行绘制
    painter.drawImage(0, 0, img);
#endif

#ifdef USE_QPICTURE
       QPainter painter(this);
       //重现绘图
       QPicture pic;
       pic.load("D:\\pic.zt");
       painter.drawPicture(0, 0, pic);
#endif
}
