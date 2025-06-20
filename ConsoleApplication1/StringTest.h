#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

extern std::string s1;
extern std::string s2;
extern std::string result1;

// 方法 2: 通过 += 追加
//s1 += ", ";
//s1 += s2;
//s1 += "!"; // s1 变为 "Hello, World!"

void testStringMethods() {
	cout << "s1 + s2= "+result1 << endl;

	std::string s = "Hello";
	s.append(", ").append("World").append("!"); // "Hello, World!"

	//3. 使用 std::ostringstream（高效混合类型拼接）
	int num = 42;
	std::ostringstream oss;
	oss << "Value: " << num << ", Text: " << "Hello"; // 混合拼接数值和字符串
	std::string result = oss.str(); // "Value: 42, Text: Hello"
	//4. 使用 std::to_string()（数值转字符串）
	int age = 25;
	double price = 9.99;
	std::string info = "Age: " + std::to_string(age) + ", Price: " + std::to_string(price);
	// "Age: 25, Price: 9.990000"

	//5. 预留缓冲区（高性能场景）
	//优点：大幅减少内存重分配次数，提升性能。
	//缺点：需要预估最终字符串长度。
	//适用场景：已知大致长度的多次拼接（如循环中）。
	//std::string result;
	result.reserve(100); // 预分配内存，减少重新分配次数
	result = "Hello";
	result += ", ";
	result += "World";
	result += "!";
	//6. C++17 的 std::string_view（避免拷贝）

	//7. C++20 的 std::format（现代化方式）
}
