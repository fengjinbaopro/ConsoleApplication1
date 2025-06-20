// Stack.hpp
#pragma once
#include <vector>
#include <stdexcept>
using namespace std;
//根据C++模板类的要求，模板类的成员函数定义必须与声明在同一个头文件中，否则会导致链接错误。
template <class T>
class Stack {
private:
    std::vector<T> elems;

public:
    void push(const T& elem);
    void pop();
    T top() const;
    bool empty() const {
        return elems.empty();
    }
};

// 模板类成员函数实现必须放在头文件中
template <class T>
void Stack<T>::push(const T& elem) {
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop() {
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const {
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back();
}

//在C++中，非模板函数在头文件中定义时若未被标记为inline，当该头文件被多个源文件包含时，会导致链接器发现多个相同符号的定义，从而引发重复定义错误。
//testStack()函数定义在头文件Template.h（或Stack.hpp）中，且未使用inline关键字。
//当多个源文件（如MyMain.cpp和其他.cpp文件）包含该头文件时，每个源文件都会生成自己的testStack()定义，导致链接时出现重复定义错误。
//inline允许函数在多个编译单元中重复定义，链接器会选取其中一个，避免冲突。在头文件中使用inline（适用于小型函数）
inline void testStack() {
    try {
        cout << "\tStack Test Begin\t" << std::endl;
        Stack<int>         intStack;  // int 类型的栈 
        Stack<string> stringStack;    // string 类型的栈 

        // 操作 int 类型的栈 
        intStack.push(7);
        cout << intStack.top() << endl;

        // 操作 string 类型的栈 
        stringStack.push("hello");
        cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
        cout << "\tStack Test End\t" << std::endl;
    }
    catch (exception const& ex) {
        cerr << "Exception: " << ex.what() << endl;
    }
}
template <typename T>
inline T const& Max(T const& a, T const& b)
{
    return a < b ? b : a;
}
inline void testMax() {
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;
}
