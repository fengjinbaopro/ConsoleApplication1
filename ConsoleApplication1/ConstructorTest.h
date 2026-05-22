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
//析构函数原则
//七、关键规则汇总
//构造不能虚，析构可以虚
//有继承、基类指针操作派生对象，必须虚析构
//析构无参、无返回、唯一不可重载
//析构顺序与构造完全相反
//override标记派生析构，校验重写合法性
class VBase {
public:
    // virtual Base() {}  // 编译报错！构造不能虚
    VBase() { cout << "基类构造\n"; }
    virtual ~VBase() { cout << "基类析构\n"; }
    //类内部实现 = 自动 inline，可安全放在头文件
    //简单函数，直接写在 .h 完全没问题
    void say(){
        cout << "直接在.h实现方法" << endl;
    };
};

class Derive : public VBase {
public:
    Derive() { cout << "派生构造\n"; }
    //**override = 强制检查我是不是在重写虚函数
    //加了安全 100 倍，不加也能运行！ * *
    ~Derive() override { cout << "Derive派生析构\n"; }//override标记派生析构，校验重写合法性
};

class NVBase {
public:
    // virtual Base() {}  // 编译报错！构造不能虚
    NVBase() { cout << "NVBase基类构造\n"; }
    ~NVBase() { cout << "NVBase基类析构\n"; }
};

class NVDerive {
public:
    // virtual Base() {}  // 编译报错！构造不能虚
    NVDerive() { cout << "NVDerive类构造\n"; }
    ~NVDerive() { cout << "NVDerive类析构\n"; }
};

void testVirtualDes();
class B;
class A
{
public:
    shared_ptr<B> bPtr;
    ~A() { cout << "A 析构\n"; }
};

class B
{
public:
    shared_ptr<A> aPtr;
    ~B() { cout << "B 析构\n"; }
};
void testMemoryLead();