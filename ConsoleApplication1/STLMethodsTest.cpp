#include <iostream>
#include <vector>
#include "STLMethodsTest.h"
#include <fstream>
using namespace std;


int testVectors()
{
    // 创建一个向量存储 int
    vector<int> vec;
    int i;

    // 显示 vec 的原始大小
    cout << "vector size = " << vec.size() << endl;

    // 推入 5 个值到向量中
    for (i = 0; i < 5; i++) {
        vec.push_back(i);
    }
    // 显示 vec 扩展后的大小
    cout << "extended vector size = " << vec.size() << endl;

    // 访问向量中的 5 个值
    for (i = 0; i < 5; i++) {
        cout << "value of vec [" << i << "] = " << vec[i] << endl;
    }

   /* push_back() 成员函数在向量的末尾插入值，如果有必要会扩展向量的大小。
    size() 函数显示向量的大小。
    begin() 函数返回一个指向向量开头的迭代器。
    end() 函数返回一个指向向量末尾的迭代器。*/

    // 使用迭代器 iterator 访问值
    vector<int>::iterator v = vec.begin();
    while (v != vec.end()) {
        cout << "value of v = " << *v << endl;
        v++;
    }
    return 0;
}

int testInitVectors() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    vec.push_back(6);
    for (int i : vec) {
        std::cout << i << " ";
    }
    return 0;
}
int testSqrt() {
    double x = 4.0;
    double y = std::sqrt(x);
    std::cout << "Square root of " << x << " is " << y << std::endl;
    return 0;
}
int testString() {
    std::string str = "Hello, C++!";
    std::cout << "Length of string: " << str.length() << std::endl;
    return 0;
}
#include <algorithm>
#include <string>

int testAlgorithm() {
    vector<int> vec = { 5, 3, 1, 4, 2 };
    sort(vec.begin(), vec.end());
    for (int i : vec) {
        std::cout << i << " "<<endl;
    }
    return 0;
}
int testCinCout()
{
    int firstNumber, secondNumber, sumOfTwoNumbers;

    cout << "输入两个整数: ";
    cin >> firstNumber >> secondNumber;

    // 相加
    sumOfTwoNumbers = firstNumber + secondNumber;

    // 输出
    cout << firstNumber << " + " << secondNumber << " = " << sumOfTwoNumbers;

    return 0;
}

int testVariables() {
    // 创建变量
    int myNum = 5;               // 整型
    float myFloatNum = 5.99;     // 单精度浮点型
    double myDoubleNum = 9.98;   // 双精度浮点型
    char myLetter = 'D';         // 字符型
    bool myBoolean = true;       // 布尔型
    string myString = "Runoob";   // 字符串

    // 输出变量
    cout << "int: " << myNum << "\n";
    cout << "float: " << myFloatNum << "\n";
    cout << "double: " << myDoubleNum << "\n";
    cout << "char: " << myLetter << "\n";
    cout << "bool: " << myBoolean << "\n";
    cout << "string: " << myString << "\n";

    return 0;
}
//在 C++ 中， <fstream> 是标准库中用于文件输入输出操作的类。它提供了一种方便的方式来读写文件。
//fstream是iostream库的一部分，支持文本和二进制文件的读写。
//fstream类是iostream库中的一个类，它继承自istream和ostream类，这意味着它既可以用于输入也可以用于输出。
int testFileWriteStream() {
    std::fstream file;
    file.open("example.txt", std::ios::out); // 以输出模式打开文件

    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1; // 文件打开失败
    }

    file << "Hello, World! this is testFileWriteStream' writed text" << std::endl; // 写入文本
    file.close(); // 关闭文件

    return 0;
}

int testFileWriteAppendStream() {
    std::fstream file;
    file.open("example.txt", std::ios::app); // 以追加模式打开文件

    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1; // 文件打开失败
    }

    file << "Appending this line to the file." << std::endl; // 追加文本
    file.close(); // 关闭文件

    return 0;
}
int testFileReadStream() {
    std::fstream file;
    file.open("example.txt", std::ios::in); // 以输入模式打开文件

    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1; // 文件打开失败
    }

    std::string line;
    while (getline(file, line)) { // 逐行读取
        std::cout << line << std::endl;
    }

    file.close(); // 关闭文件

    return 0;
}
//sstream 是 C++ 标准库中的一个组件，它提供了一种方便的方式来处理字符串流（可以像处理流一样处理字符串）。