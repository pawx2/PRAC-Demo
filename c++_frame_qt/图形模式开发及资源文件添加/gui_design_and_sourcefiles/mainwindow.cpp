#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionopen->setIcon(QIcon(":/images/Image/down.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

