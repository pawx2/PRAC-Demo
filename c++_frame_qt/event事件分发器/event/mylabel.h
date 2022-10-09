#ifndef MYLABEL_H
#define MYLABEL_H

#include<QLabel>

class mylabel : public QLabel
{
public:
    mylabel(QWidget* parent);

    //鼠标进入事件
    void enterEvent(QEnterEvent* ev);

    //鼠标离开事件
    void leaveEvent(QEvent* ev);

    //鼠标按下事件
    virtual void mousePressEvent(QMouseEvent* ev);

    //鼠标释放事件
    virtual void mouseReleaseEvent(QMouseEvent* ev);

    //鼠标移动事件
    virtual void mouseMoveEvent(QMouseEvent* ev);

    //通过event事件分发器拦截事件
    bool event(QEvent* e);
};

#endif // MYLABEL_H
