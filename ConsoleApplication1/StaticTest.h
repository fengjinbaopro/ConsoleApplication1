#pragma once
#include "CommonInclude.h"
class StaticTest
{
public:
	static  int sharedVar;  // 声明
	char16_t name;
};
// 不要在.h文件中定义函数声明，会导致重定义。
void testStatic();

