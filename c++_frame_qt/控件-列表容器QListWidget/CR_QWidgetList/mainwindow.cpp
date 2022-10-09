#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //新建选项
    QListWidgetItem* sen1 = new QListWidgetItem("窗前明月光");
    QListWidgetItem* sen2 = new QListWidgetItem("疑是地上霜");
    QListWidgetItem* sen3 = new QListWidgetItem("举头望明月");
    QListWidgetItem* sen4 = new QListWidgetItem("低头思故乡");
    //分别设置右对齐、水平居中、左对齐
    sen1->setTextAlignment(Qt::AlignRight);
    sen2->setTextAlignment(Qt::AlignHCenter);
    sen3->setTextAlignment(Qt::AlignLeft);
    //将QWidgetListItem添加到QListWidget中
    ui->listWidget->addItem(sen1);
    ui->listWidget->addItem(sen2);
    ui->listWidget->addItem(sen3);
    ui->listWidget->addItem(sen4);

    //通过链表批量加入到QListWidget中
    QStringList list;
    list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
    ui->listWidget->addItems(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}

