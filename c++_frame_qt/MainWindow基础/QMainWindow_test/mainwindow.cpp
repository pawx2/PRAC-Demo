#include "mainwindow.h"
#include "ui_mainwindow.h"

/*QMainWindow中仅允许拥有一个的部件*/
#include<QMenuBar>
#include<QStatusBar>
/*QMainWindow中允许拥有多个的部件*/
#include<QToolBar>
#include<QDockWidget>
/*通用部件*/
#include<QPushButton>
#include<QLabel>
#include<QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * 仅能设置一个的使用set开头函数，可以设置多个的使用add开头函数。
     * 共五个部件可设置:    中心部件 菜单栏 状态栏 工具栏 铆接部件
    */

    /*中心部件 其它部件位置依据此部件设置 仅能设置一个*/
    QTextEdit* edit = new QTextEdit(this);
    setCentralWidget(edit);

    /*菜单栏 仅能设置一个*/
    QMenuBar* menubar = new QMenuBar(this);  //新建菜单栏并添加到对象树中
    //添加菜单
    QMenu* fileMenu = menubar->addMenu("文件");
    QMenu* editMenu = menubar->addMenu("编辑");
    //添加菜单项
    QAction* file_item = fileMenu->addAction("打开");
    fileMenu->addSeparator();               //添加分隔符
    QAction* new_item = fileMenu->addAction("新建");
    setMenuBar(menubar);                    //为窗口设定菜单栏

    /*状态栏 仅能设置一个*/
    QStatusBar* stbar = new QStatusBar(this);   //新建状态栏并添加到对象树中
    //添加标签控件显示信息
    QLabel* left_label = new QLabel("左侧提示信息", this);
    stbar->addWidget(left_label);               //添加信息至左侧
    QLabel* right_label = new QLabel("右侧提示信息", this);
    stbar->addPermanentWidget(right_label);     //添加信息至右侧
    setStatusBar(stbar);                        //为窗口设置状态栏

    /*工具栏 可以设置多个*/
    QToolBar* toolbar = new QToolBar(this);                               //新建工具栏并添加到对象树中
    toolbar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea); //仅允许左右停靠
    toolbar->setFloatable(false);               //设置不允许浮动
    toolbar->setMovable(false);                 //设置不可移动
    //工具栏中添加内容
    toolbar->addAction(file_item);              //添加菜单栏中相同的项
    toolbar->addAction(new_item);
    QAction* ac1 = new QAction("画笔", this);
    toolbar->addAction(ac1);
    toolbar->addSeparator();    //添加分隔符
    QPushButton* btn = new QPushButton("press me", this);
    toolbar->addWidget(btn);    //添加控件
    addToolBar(Qt::LeftToolBarArea, toolbar);               //为窗口添加工具栏并且初始位置置于左侧

    /*铆接部件(浮动窗口) 可以设置多个*/
    QDockWidget* dockw = new QDockWidget(this);     //新建铆接部件并添加到对象树中
    dockw->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);   //设置允许停靠范围 仅上下位置
    addDockWidget(Qt::BottomDockWidgetArea, dockw);           //为窗口添加铆接部件，并设置初始位置为下方

}

MainWindow::~MainWindow()
{
    delete ui;
}

