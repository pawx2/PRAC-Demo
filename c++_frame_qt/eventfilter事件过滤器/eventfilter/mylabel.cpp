#include "mylabel.h"

#include<QString>
#include<QMouseEvent>
#include<QDebug>

/*Summary*/
/*
 * 鼠标事件
 * 鼠标进入事件   enterEvent
 * 鼠标离开事件   leaveEvent
 * 鼠标按下事件   mousePressEvent
 * 鼠标施放事件   mouseReleaseEvent
 * 鼠标移动事件   mouseMoveEvent
 * 获取局部坐标   ev->x(),ev->y()
 * 获取全局坐标   ev->globalX(),ev->globalY()
 * 判断按键按下   ev->button()    Qt::LeftButton Qt::RightButton
 * 判断组合按键   ev->buttons()   通过按位与运算使用
 * 格式化字符串   QString("%1, %2").arg(<参数1>).arg(<参数2>)
*/

mylabel::mylabel(QWidget* parent) : QLabel(parent)
{
    //设置鼠标追踪状态 默认为false
    setMouseTracking(true);
}

//鼠标进入事件
void mylabel::enterEvent(QEnterEvent* ev)
{
    this->setText("鼠标进入了");
    qDebug() << "鼠标进入了";
}

//鼠标离开事件
void mylabel::leaveEvent(QEvent* ev)
{
    this->setText("鼠标离开了");
    qDebug() << "鼠标离开了";
}

//鼠标按下事件 瞬间事件
void mylabel::mousePressEvent(QMouseEvent* ev)
{
    this->setText("你再点击试试看！");
    //左右键判断，按下左键打印局部位置 按下右键打印全局位置
    if(ev->button() == Qt::LeftButton)
    {
        //x,y基于控件而非全局
        QString str = QString("左键按下，鼠标按下了 x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
    else if(ev->button() == Qt::RightButton)
    {
        //全局位置
        QString globalstr = QString("右键按下，鼠标在全局位置：x = %1, y = %2按下").arg(ev->globalX()).arg(ev->globalY());
        qDebug() << globalstr;
    }

}

//鼠标释放事件 瞬间事件
void mylabel::mouseReleaseEvent(QMouseEvent* ev)
{
    this->setText("鼠标松开了");
}

//鼠标移动事件 过程事件
void mylabel::mouseMoveEvent(QMouseEvent* ev)
{
    this->setText("鼠标移动了！");
    //使用buttons可以在过程事件中监听多个按键
    if(ev->buttons() & Qt::LeftButton)
    {
        qDebug() << "鼠标左键按着走";
    }
    if(ev->buttons() & Qt::RightButton)
    {
        qDebug() << "鼠标右键按着走";
    }

    //鼠标追踪获得的信息
    QString trackstr = QString("鼠标追踪：%1， %2").arg(ev->x()).arg(ev->y());
    qDebug() << trackstr;
}

//bool mylabel::event(QEvent* e)
//{
//    //如果鼠标按下，在event事件分发器中进行拦截。不向下进行分发
//    if(e->type() == QEvent::MouseButtonPress)
//    {
//        QMouseEvent* ev = static_cast<QMouseEvent* >(e);
//        QString str = QString("鼠标在%1， %2位置点击事件被event所拦截！").arg(ev->x()).arg(ev->y());
//        qDebug() << str;
//        return true;
//    }
//    return QLabel::event(e);
//}
