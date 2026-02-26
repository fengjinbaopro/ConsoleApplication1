#pragma once
#include "CommonInclude.h"
class Base{
public:
	virtual ~Base(){}
};
class Derived :public Base {
public:
	//Derived() {};
	//virtual ~Derived(){}
	int id = 1;
};
void testDynamicCast();
void testStaticCast();
