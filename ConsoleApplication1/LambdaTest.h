#pragma once
#include "CommonInclude.h"

void testLamba() {
	int value = 100;
	//值捕获
	auto fvalue = [value](int a, int b)->int {
		//value++;使用名称引用的不可修改该值
		return value + a + b;
		};
	cout << "fvalue [value](10, 10)" << fvalue(10, 10) << endl;
	cout << "value " << value << endl;


	//引用捕获
	auto fref = [&value](int a, int b) {
		value++;
		return value + a + b;
	};
	cout << "fvalue " << fref(10, 10) << endl;
	cout << "value " << value << endl;

	//隐式捕获
	//=是值捕获
	//&是引用捕获
	int age =30;
	auto ftran = [&](int a, int b) {
		value++;
		age++;
		return  value + a + b;
		};
	cout << "fvalue " << fref(10, 10) << endl;
	cout << "value " << value << endl;
	cout << "age " << age << endl;

	//隐式捕获
	//int age = 30;
	//auto ftran = [](int a, int b) { //必须指定，没有默认的说法。
	//std::string::from
	std::to_string(12);



}