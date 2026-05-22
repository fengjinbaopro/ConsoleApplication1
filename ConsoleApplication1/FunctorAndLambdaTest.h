#pragma once
#include "CommonInclude.h"

//本质：重载() 运算符的类，可以像函数一样调用，可存状态、传参。
struct FunObjNoP {
	void operator()() {
		cout << "FunObjNoP无参函数对象执行" << endl;
	}
};
struct FunObjOneP
{
	int id;
	string name;
	int operator()(int a,int b) {
		return a + b;
	}
	void say() {
		cout <<"FunObjOneP say" << name << endl;
	}
};

// 3. 带成员变量 有状态函数对象
struct CountObj
{
	int cnt = 0;
	void operator()()
	{
		cnt++;
		cout << "CountObj 计数：" << cnt << endl;
	}
};

void testFunctorAndLambda();
