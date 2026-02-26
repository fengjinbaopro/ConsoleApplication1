#include "CastTest.h"
//当转换关系明确且安全时，使用static_cast
//当需要运行时类型检查时，使用dynamic_cast
//优先考虑设计改进（如使用虚函数）减少类型转换需求
void testStaticCast() {
	int i = 42;
	double d = (double)i;
	double d2 = static_cast<double>(i);
	float f = 3.14f;
	int j = static_cast<int>(f);

	Derived derived;
	Base* b = static_cast<Base*>(&derived);

	void* p = malloc(sizeof(int));
	int* ip = static_cast<int*>(p);
	free(p);

	enum Color { RED, GREEN, BLUE };
	Color c = GREEN;
	int colorValue = static_cast<int>(c);
}
//当转换关系明确且安全时，使用static_cast
//当需要运行时类型检查时，使用dynamic_cast
//优先考虑设计改进（如使用虚函数）减少类型转换需求
void testDynamicCast() {
	Base* b = new Derived;
	Derived* d = dynamic_cast<Derived*>(b);

	Base* b2 = new Base;
	//Derived d2 = dynamic_cast<Derived*>(b2);//Derived* d2 = dynamic_cast<Derived*>(b2); // 失败：返回nullptr
	Derived* d2 = (Derived*)b2;
	cout << "d2:" << d2->id << endl;
	Derived* d3 = static_cast<Derived*>(b2);
	cout << "d3:" << d3->id << endl;

}