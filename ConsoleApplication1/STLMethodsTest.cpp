#include <iostream>
#include <vector>
#include "STLMethodsTest.h"
#include <fstream>
using namespace std;


int testVectors()
{
    // ����һ�������洢 int
    vector<int> vec;
    int i;

    // ��ʾ vec ��ԭʼ��С
    cout << "vector size = " << vec.size() << endl;

    // ���� 5 ��ֵ��������
    for (i = 0; i < 5; i++) {
        vec.push_back(i);
    }
    // ��ʾ vec ��չ��Ĵ�С
    cout << "extended vector size = " << vec.size() << endl;

    // ���������е� 5 ��ֵ
    for (i = 0; i < 5; i++) {
        cout << "value of vec [" << i << "] = " << vec[i] << endl;
    }

   /* push_back() ��Ա������������ĩβ����ֵ������б�Ҫ����չ�����Ĵ�С��
    size() ������ʾ�����Ĵ�С��
    begin() ��������һ��ָ��������ͷ�ĵ�������
    end() ��������һ��ָ������ĩβ�ĵ�������*/

    // ʹ�õ����� iterator ����ֵ
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

    cout << "������������: ";
    cin >> firstNumber >> secondNumber;

    // ���
    sumOfTwoNumbers = firstNumber + secondNumber;

    // ���
    cout << firstNumber << " + " << secondNumber << " = " << sumOfTwoNumbers;

    return 0;
}

int testVariables() {
    // ��������
    int myNum = 5;               // ����
    float myFloatNum = 5.99;     // �����ȸ�����
    double myDoubleNum = 9.98;   // ˫���ȸ�����
    char myLetter = 'D';         // �ַ���
    bool myBoolean = true;       // ������
    string myString = "Runoob";   // �ַ���

    // �������
    cout << "int: " << myNum << "\n";
    cout << "float: " << myFloatNum << "\n";
    cout << "double: " << myDoubleNum << "\n";
    cout << "char: " << myLetter << "\n";
    cout << "bool: " << myBoolean << "\n";
    cout << "string: " << myString << "\n";

    return 0;
}
//�� C++ �У� <fstream> �Ǳ�׼���������ļ���������������ࡣ���ṩ��һ�ַ���ķ�ʽ����д�ļ���
//fstream��iostream���һ���֣�֧���ı��Ͷ������ļ��Ķ�д��
//fstream����iostream���е�һ���࣬���̳���istream��ostream�࣬����ζ�����ȿ�����������Ҳ�������������
int testFileWriteStream() {
    std::fstream file;
    file.open("example.txt", std::ios::out); // �����ģʽ���ļ�

    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1; // �ļ���ʧ��
    }

    file << "Hello, World! this is testFileWriteStream' writed text" << std::endl; // д���ı�
    file.close(); // �ر��ļ�

    return 0;
}

int testFileWriteAppendStream() {
    std::fstream file;
    file.open("example.txt", std::ios::app); // ��׷��ģʽ���ļ�

    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1; // �ļ���ʧ��
    }

    file << "Appending this line to the file." << std::endl; // ׷���ı�
    file.close(); // �ر��ļ�

    return 0;
}
int testFileReadStream() {
    std::fstream file;
    file.open("example.txt", std::ios::in); // ������ģʽ���ļ�

    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1; // �ļ���ʧ��
    }

    std::string line;
    while (getline(file, line)) { // ���ж�ȡ
        std::cout << line << std::endl;
    }

    file.close(); // �ر��ļ�

    return 0;
}
//sstream �� C++ ��׼���е�һ����������ṩ��һ�ַ���ķ�ʽ�������ַ�����������������һ�������ַ�������