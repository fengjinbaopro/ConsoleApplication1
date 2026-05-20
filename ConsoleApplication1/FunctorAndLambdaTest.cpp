#include "FunctorAndLambdaTest.h"

void testFunctorAndLambda()
{
	FunObjNoP f1;
	f1();// 普通调用

	FunObjNoP()();// 匿名临时对象调用

	FunObjOneP f2;
	f2.name = "feng";
	f2.say();
	cout <<"FunObjOneP(int a,int b)" << f2(10, 20) << endl;

	CountObj c;
	c();
	c();
	c();
}
