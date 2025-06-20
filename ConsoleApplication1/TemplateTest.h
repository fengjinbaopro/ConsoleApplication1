// Stack.hpp
#pragma once
#include <vector>
#include <stdexcept>
using namespace std;
//����C++ģ�����Ҫ��ģ����ĳ�Ա�������������������ͬһ��ͷ�ļ��У�����ᵼ�����Ӵ���
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

// ģ�����Ա����ʵ�ֱ������ͷ�ļ���
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

//��C++�У���ģ�庯����ͷ�ļ��ж���ʱ��δ�����Ϊinline������ͷ�ļ������Դ�ļ�����ʱ���ᵼ�����������ֶ����ͬ���ŵĶ��壬�Ӷ������ظ��������
//testStack()����������ͷ�ļ�Template.h����Stack.hpp���У���δʹ��inline�ؼ��֡�
//�����Դ�ļ�����MyMain.cpp������.cpp�ļ���������ͷ�ļ�ʱ��ÿ��Դ�ļ����������Լ���testStack()���壬��������ʱ�����ظ��������
//inline�������ڶ�����뵥Ԫ���ظ����壬��������ѡȡ����һ���������ͻ����ͷ�ļ���ʹ��inline��������С�ͺ�����
inline void testStack() {
    try {
        cout << "\tStack Test Begin\t" << std::endl;
        Stack<int>         intStack;  // int ���͵�ջ 
        Stack<string> stringStack;    // string ���͵�ջ 

        // ���� int ���͵�ջ 
        intStack.push(7);
        cout << intStack.top() << endl;

        // ���� string ���͵�ջ 
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
