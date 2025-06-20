#pragma once
#include "CommonInclude.h"
typedef int Myint;

namespace Ui {
    class MainWindow;
}
class QMainWindow
{
public:
    string name;
	QMainWindow();
    QMainWindow(string name);
	~QMainWindow();

private:
};
//不要在.h文件中定义函数声明，会导致重定义。
//QMainWindow::QMainWindow()
//{
//    this->name = "QMainWindow";
//}
//
//QMainWindow::~QMainWindow()
//{
//}
class MainWindow : public QMainWindow
{
    

public:
    MainWindow();//在C++中，默认构造函数（无参构造）不能有初始化列表参数。
    MainWindow(string name);
    string name;

private:
    Ui::MainWindow* ui;
};
void testContructor();