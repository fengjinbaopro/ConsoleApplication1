#include <string>
#include <iostream>
using namespace std;
#include <sstream>
#include "StringTest.h"

std::string s1 = "Hello";
std::string s2 = "World";
// 方法 1: 直接相加
std::string result1 = s1 + ", " + s2 + "!"; // "Hello, World!"
//string::at(s1, 10);