#include "MemoryTest.h"
#include "CommonInclude.h"

class Box
{
public:
    Box() {
        cout << "调用构造函数！" << endl;
    }
    ~Box() {
        cout << "调用析构函数！" << endl;
    }
};


void testMemory() {
    Box myBoxArray[4];
    //delete[] 只能用于释放通过 new[] 动态分配的堆内存。
    //delete[] myBoxArray; // 删除数组
}


