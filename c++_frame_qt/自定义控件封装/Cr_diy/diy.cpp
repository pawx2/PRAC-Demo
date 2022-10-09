#include "diy.h"
#include "ui_diy.h"

diy::diy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diy)
{
    ui->setupUi(this);
    /*自定义封装控件*/
    //QSpinBox移动 QSlider跟着移动
    //重载信号使用函数指针传参
    void(QSpinBox::* spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spSignal, ui->horizontalSlider, &QSlider::setValue);

    //QSlider移动 QSpinBox跟着改变
    void(QSlider::*slSignal)(int) = &QSlider::valueChanged;
    connect(ui->horizontalSlider, slSignal, ui->spinBox, &QSpinBox::setValue);
}

diy::~diy()
{
    delete ui;
}

void diy::setValue(int num)
{
    ui->spinBox->setValue(num);
    return;
}

int diy::getValue()
{
    return ui->spinBox->value();
}
