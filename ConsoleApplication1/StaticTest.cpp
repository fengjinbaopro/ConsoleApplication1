#include "StaticTest.h"

//为什么需要这样
//存储分配：静态成员变量不属于任何特定类实例，需要在全局数据区分配存储
//单一定义规则：确保整个程序中只有一个定义
//链接需求：让链接器能找到变量的实际地址
int StaticTest::sharedVar = 0;  // 定义

void testStatic() {
	 cout << "Null value:" << NULL << endl;
	 cout << "nullptr value:" << (void*)0 << endl;
	 StaticTest::sharedVar = 10;
	 cout << "StaticTest sharedVar:" << StaticTest::sharedVar << endl;
}