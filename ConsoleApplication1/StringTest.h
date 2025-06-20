#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

extern std::string s1;
extern std::string s2;
extern std::string result1;

// ���� 2: ͨ�� += ׷��
//s1 += ", ";
//s1 += s2;
//s1 += "!"; // s1 ��Ϊ "Hello, World!"

void testStringMethods() {
	cout << "s1 + s2= "+result1 << endl;

	std::string s = "Hello";
	s.append(", ").append("World").append("!"); // "Hello, World!"

	//3. ʹ�� std::ostringstream����Ч�������ƴ�ӣ�
	int num = 42;
	std::ostringstream oss;
	oss << "Value: " << num << ", Text: " << "Hello"; // ���ƴ����ֵ���ַ���
	std::string result = oss.str(); // "Value: 42, Text: Hello"
	//4. ʹ�� std::to_string()����ֵת�ַ�����
	int age = 25;
	double price = 9.99;
	std::string info = "Age: " + std::to_string(age) + ", Price: " + std::to_string(price);
	// "Age: 25, Price: 9.990000"

	//5. Ԥ���������������ܳ�����
	//�ŵ㣺��������ڴ��ط���������������ܡ�
	//ȱ�㣺��ҪԤ�������ַ������ȡ�
	//���ó�������֪���³��ȵĶ��ƴ�ӣ���ѭ���У���
	//std::string result;
	result.reserve(100); // Ԥ�����ڴ棬�������·������
	result = "Hello";
	result += ", ";
	result += "World";
	result += "!";
	//6. C++17 �� std::string_view�����⿽����

	//7. C++20 �� std::format���ִ�����ʽ��
}
