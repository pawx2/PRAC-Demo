#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置树的水平头
    ui->treeWidget->setHeaderLabels(QStringList() << "控件" << "说明");
    //为树创建顶层节点并且添加到树容器中
    QTreeWidgetItem* item1 = new QTreeWidgetItem(QStringList() << "QListWidget");
    QTreeWidgetItem* item2 = new QTreeWidgetItem(QStringList() << "QTreeWidget");
    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    //创建对应头节点的子节点并且添加到对应的头节点中
    QTreeWidgetItem* item1_child = new QTreeWidgetItem(QStringList() << "列表容器" << "用于装入多个列表项并进行显示");
    QTreeWidgetItem* item2_child = new QTreeWidgetItem(QStringList() << "树容器" << "用于容纳构建类似文件树的结构");
    item1->addChild(item1_child);
    item2->addChild(item2_child);
}

MainWindow::~MainWindow()
{
    delete ui;
}

