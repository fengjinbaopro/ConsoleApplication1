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
//��Ҫ��.h�ļ��ж��庯���������ᵼ���ض��塣
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
    MainWindow();//��C++�У�Ĭ�Ϲ��캯�����޲ι��죩�����г�ʼ���б������
    MainWindow(string name);
    string name;

private:
    Ui::MainWindow* ui;
};
void testContructor();