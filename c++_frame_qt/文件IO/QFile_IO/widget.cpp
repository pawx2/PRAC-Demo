#include "widget.h"
#include "ui_widget.h"

#include<QFileDialog>
#include<QFile>
#include<QTextCodec>

//#define READ_ALL
#define READ_LINES

#define UTF_8
//#define GBK

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击选取文件按钮，弹出文件对话框
    connect(ui->pushButton, &QPushButton::clicked, [=]()->void{
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "D:\\projects\\qt_lab\\QFile_IO");
        //将路径放入到lineEdit中
        ui->lineEdit->setText(path);

        //编码格式类 文件IO一般默认为utf-8编码
        QTextCodec* codec = QTextCodec::codecForName("gbk");

        //读取内容并将其放置到textEdit中
        QFile file(path);                   //参数为读取文件中的路径
        file.open(QIODevice::ReadOnly);     //只读方式打开
        //////////////////文件读取方式//////////////////////
#ifdef READ_ALL
        QByteArray array = file.readAll();  //读取所有数据到字节数组中
#endif
#ifdef READ_LINES
        QByteArray array;   //按行读取，将全部内容读入
        while(!file.atEnd())    //判断是否到达文件尾部
        {
            array += file.readLine();
        }
#endif

        ///////////////文件编码////////////////
        //将读取到的数据 放入到textEdit中
#ifdef UTF_8
        //QFile默认支持格式为utf-8
        ui->textEdit->setText(array);
#endif

#ifdef GBK
        //转码后再放入textEdit中
        ui->textEdit->setText(codec->toUnicode(array));
#endif
        /*
         * 这里仅仅只能支持一种格式编码文件的正常显示
         * 如果要支持多种
         * 读入文件时判断文件格式
         * 根据读入文件格式进行转码，进而进行显示
        */
        //关闭打开的文件
        file.close();

        //写文件
        file.open(QIODevice::Append);    //追加方式进行写文件
        file.write("呵呵呵呵呵");
        file.close();

    });
}

Widget::~Widget()
{
    delete ui;
}

