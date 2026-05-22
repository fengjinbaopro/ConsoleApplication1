#include "ConstructorTest.h"


void testContructor() {
	MainWindow::MainWindow();
}
// 头文件中声明了但未实现
QMainWindow::QMainWindow() {
};

QMainWindow::QMainWindow(string name) {
	this->name = name;
}
QMainWindow::~QMainWindow() {};
//无法解析的外部符号 ，如果声明了，但是没有进行定义，就会产生
MainWindow::MainWindow() {

}
//在C++中，默认构造函数（无参构造）不能有初始化列表参数。
MainWindow::MainWindow(string name):QMainWindow("QMainWindow"), name("sunwindow") {//MainWindow::MainWindow(QWidget *parent) 后面的冒号和逗号语法是成员初始化列表
	/*2必要场景
	初始化 const 成员
	初始化引用成员
	初始化没有默认构造函数的类成员
	初始化基类（如本例）*/
	/*3执行顺序
		初始化按类声明顺序执行（非初始化列表顺序）*/
	cout << "MainWindow name" << name << endl;

}
void testVirtualDes()
{
	// 基类指针指向派生类对象
	VBase* p = new Derive;
	delete p;
	NVBase* nv1 = new NVBase;
	delete nv1;
}

void testMemoryLead()
{
	{
		{
			shared_ptr<A> a = make_shared<A>();
			shared_ptr<B> b = make_shared<B>();
			// 互相持有，形成循环引用
			a->bPtr = b;
			b->aPtr = a;
		}
		// 出作用域，引用计数无法归0，不会打印析构，内存泄漏
		cout << "作用域结束\n";
	}
}

