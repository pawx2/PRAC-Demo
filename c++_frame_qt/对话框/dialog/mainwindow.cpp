#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDialog>
#include<QMessageBox>
#include<QColorDialog>
#include<QtDebug>
#include<QFileDialog>
#include<QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击新建按钮，弹出对话框
    connect(ui->actionnew, &QAction::triggered, [=](){
       //对话框 分类：模态对话框    创建该窗口后不可以对其它窗口进行操作
       //          非模态对话框   创建该窗口后可以对其它窗口进行操作

        //创建模态对话框
       //QDialog dig(this);
       //dig.exec();

       //创建非模态对话框
//       QDialog* dig2 = new QDialog(this);
//       dig2->setAttribute(Qt::WA_DeleteOnClose);
//       dig2->show();

        //消息对话框
//        QMessageBox::critical(this, "Critical", "wdnmd!");
//        QMessageBox::information(this, "information", "tnnd");
//        QMessageBox::question(this, "question", "nmd");
//        QMessageBox::warning(this, "warning", "nzgsb");

        //颜色对话框
//        QColor color = QColorDialog::getColor(QColor(255, 0, 0), this);
//        qDebug() << "r = " << color.red() << "g = " << color.green() << "b = " << color.blue();
        //文件对话框
        QFileDialog::getOpenFileName(this);

        //字体对话框
        bool flag;
        QFontDialog::getFont(&flag, QFont("华文彩云", 24), this);

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

