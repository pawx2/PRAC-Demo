#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*TableWidget列表容器*/

    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置行数
    ui->tableWidget->setRowCount(5);

    //设置水平头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");

    //新建数据项并进行设置
    QStringList names, sexs, ages;
    names << "小明" << "小红" << "李华" << "李明华" << "穿山甲";
    sexs << "男" << "女" << "男" << "男" << "未知";
    ages << "121" << "18" << "20" << "49" << "800";
    for(int r = 0; r < 5; r++)
    {
        ui->tableWidget->setItem(r, 0, new QTableWidgetItem(names[r]));
        ui->tableWidget->setItem(r, 1, new QTableWidgetItem(sexs[r]));
        ui->tableWidget->setItem(r, 2, new QTableWidgetItem(ages[r]));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

