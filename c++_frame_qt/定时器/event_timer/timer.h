#ifndef TIMER_H
#define TIMER_H
#include <QWidget>
#include <QLabel>
#include<QTimerEvent>

class timer : public QLabel
{
    Q_OBJECT
public:
    explicit timer(QWidget *parent = nullptr);
signals:

};

#endif // TIMER_H
