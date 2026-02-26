#pragma once
#include "CommonInclude.h"

void testLamba() {
	int value = 100;
	auto fvalue = [value](int a, int b)->int {
		//value++;使用名称引用的不可修改该值
		return value + a + b;
		};
	cout << "fvalue " << fvalue(10, 10) << endl;
	cout << "value " << value << endl;

	auto fref = [&value](int a, int b) {
		value++;
		return value + a + b;
	};
	cout << "fvalue " << fref(10, 10) << endl;
	cout << "value " << value << endl;

	int age =30;
	auto ftran = [&](int a, int b) {
		value++;
		age++;
		return value + a + b;
		};
	cout << "fvalue " << fref(10, 10) << endl;
	cout << "value " << value << endl;
	cout << "age " << age << endl;


}