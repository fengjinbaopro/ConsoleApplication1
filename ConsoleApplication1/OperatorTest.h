#pragma once
//函数重载 :在同一个作用域内，可以声明几个功能类似的同名函数，但是这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同。您不能仅通过返回类型的不同来重载函数。
//重载的运算符是带有特殊名称的函数，函数名是由关键字 operator 和其后要重载的运算符符号构成的。与其他函数一样，重载运算符有一个返回类型和一个参数列表。

#include <iostream>
#include<set>
#include <unordered_map>
#include <map>
#include <cassert>​
#include <iostream>​
#include <memory>​
#include <string>​
#include <type_traits>​
#include <vector>​
using namespace std;

class Box
{
public:

    double getVolume(void)
    {
        return length * breadth * height;
    }
    void setLength(double len)
    {
        length = len;
    }

    void setBreadth(double bre)
    {
        breadth = bre;
    }

    void setHeight(double hei)
    {
        height = hei;
    }
    // 重载 + 运算符，用于把两个 Box 对象相加
    Box operator+(const Box& b)
    {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }
public:
    double length;      // 长度
    double breadth;     // 宽度
    double height;      // 高度
};
// 程序的主函数
int testOperatorPlus()
{
    Box Box1;                // 声明 Box1，类型为 Box
    Box Box2;                // 声明 Box2，类型为 Box
    Box Box3;                // 声明 Box3，类型为 Box
    double volume = 0.0;     // 把体积存储在该变量中

    // Box1 详述
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(8.0);

    // Box2 详述
    Box2.setLength(10.0);
    Box2.setBreadth(10.0);
    Box2.setHeight(10.0);

    // Box1 的体积
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume << endl;

    // Box2 的体积
    volume = Box2.getVolume();
    cout << "Volume of Box2 : " << volume << endl;

    // 把两个对象相加，得到 Box3
    Box3 = Box1 + Box2;

    // Box3 的体积
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume << endl;
    cout << "l" << Box3.length << "w:" << Box3.breadth << ",h" << Box3.height << endl;

    return 0;
}
//函数调用运算符() 可以被重载用于类的对象。当重载() 时，您不是创造了一种新的调用函数的方式，相反地，这是创建一个可以传递任意数目参数的运算符函数。
class Distance
{
private:
    int feet;             // 0 到无穷
    int inches;           // 0 到 12
public:
    // 所需的构造函数
    Distance() {
        feet = 0;
        inches = 0;
    }
    Distance(int f, int i) {
        feet = f;
        inches = i;
    }
    // 重载函数调用运算符
    Distance operator()(int a, int b, int c)
    {
        Distance D;
        // 进行随机计算
        D.feet = a + c + 10;
        D.inches = b + c + 100;
        return D;
    }
    // 显示距离的方法
    void displayDistance()
    {
        cout << "F: " << feet << " I:" << inches << endl;
    }

};

int testOperatorBracket()
{
    Distance D1(11, 10), D2;

    cout << "First Distance : ";
    D1.displayDistance();

    D2 = D1(10, 10, 10); // invoke operator()
    cout << "Second Distance :";
    D2.displayDistance();

    return 0;
}
void testSet() {
    std::set<int> mSet;
    mSet.insert(4);
    mSet.insert(3);
    mSet.insert(2);
    mSet.insert(1);
    std::cout << "mSet content";
    for (int num : mSet) {
        std::cout << num << " ";
    }
    mSet.find(8) == mSet.end();
    std::cout << endl;

}

void testMap() {
    //无序
    unordered_map<string, int> hashTable;
    hashTable["apple"] = 10;
    cout << hashTable["apple"] << ","; // 输出 10

    //有序
    map<string, int> myMap;
    myMap["apple"] = 10;
    cout << myMap["apple"] << ","; // 输出 10


    unordered_map<int, int> numTable;
    numTable[1] = 2;
    cout << numTable[1] << ",";
    cout << numTable[0] << ",";
    cout << numTable[2] << ",";

    unordered_map<int, int>::iterator it = numTable.find(1);
    cout << endl;
};

//题目描述
//用 C++ 实现一个模板类 Vector，模拟标准库 std::vector 的核心功能。​
//需要实现 : 默认构造函数, operator[], push_back, pop_back, size, capacity。​


template <typename T>
class Vector {
private:
    T* data = nullptr;    // 底层数组
    size_t m_size = 0;    // 当前元素个数
    size_t m_capacity = 0;// 容量

    // 扩容：2倍增长
    void reserve(size_t new_capacity) {
        if (new_capacity <= m_capacity) return;

        // 申请新内存
        T* new_data = new T[new_capacity];

        // 拷贝/移动旧数据
        for (size_t i = 0; i < m_size; ++i) {
            new_data[i] = std::move(data[i]);
        }

        // 释放旧内存
        delete[] data;
        data = new_data;
        m_capacity = new_capacity;
    }

public:
    // 默认构造
    Vector() = default;

    // 析构函数
    ~Vector() {
        delete[] data;
    }

    // 访问运算符
    T& operator[](size_t index) {
        return data[index];
    }

    // 尾部添加（右值版本，触发move）
    void push_back(T&& val) {
        if (m_size >= m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        data[m_size++] = std::move(val);
    }

    // 删除尾部
    void pop_back() {
        if (m_size > 0) {
            m_size--;
        }
    }

    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }
};

// ==========================================​
// 测试代码 (请勿修改)​
// ==========================================​

//struct Tracker {
//​
//static int constructed_count; ​
//static int destructed_count; ​
//static int copy_count; ​
//static int move_count; ​
//std::string name; ​
//Tracker(std::string n) : name(std::move(n)) { constructed_count++; }​
//~Tracker() { destructed_count++; }​
//Tracker(const Tracker& other) : name(other.name) {
//​
//constructed_count++; ​
//copy_count++; ​
//}​
//Tracker(Tracker&& other) noexcept : name(std::move(other.name)) {
//​
//    constructed_count++; ​
//    move_count++; ​
//}​
//Tracker() = delete; ​
//}; ​
//
//int Tracker::constructed_count = 0; ​
//    int Tracker::destructed_count = 0; ​
//    int Tracker::copy_count = 0; ​
//    int Tracker::move_count = 0; ​
//
//    int main() {
//    ​
//    { ​
//        Vector<Tracker> vec; ​
//        assert(vec.size() == 0); ​
//        assert(vec.capacity() == 0); ​
//
//        vec.push_back(Tracker("A")); ​
//        assert(vec.size() == 1); ​
//        assert(vec.capacity() == 1); ​
//        assert(vec[0].name == "A"); ​
//
//        vec.push_back(Tracker("B")); ​
//        assert(vec.size() == 2); ​
//        assert(vec.capacity() == 2); ​
//        assert(vec[1].name == "B"); ​
//
//        vec.push_back(Tracker("C")); ​
//        assert(vec.size() == 3); ​
//        assert(vec.capacity() == 4); ​
//        assert(vec[2].name == "C"); ​
//
//        vec.pop_back(); ​
//        assert(vec.size() == 2); ​
//        assert(vec.capacity() == 4); ​
//    }​
//
//        assert(Tracker::constructed_count == 9); ​
//
//        std::cout << "Passed" << std::endl; ​
//        return 0; ​
//}