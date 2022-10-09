#ifndef DIY_H
#define DIY_H

#include <QWidget>

namespace Ui {
class diy;
}

class diy : public QWidget
{
    Q_OBJECT

public:
    explicit diy(QWidget *parent = nullptr);
    ~diy();

    void setValue(int num);

    int getValue();

private:
    Ui::diy *ui;
};

#endif // DIY_H
