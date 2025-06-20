#pragma once
#include <iostream>
using namespace std;
#define MIN(a,b) (((a)<(b)) ? a : b)
#define DEBUG
//# 和 ## 预处理运算符在 C++ 和 ANSI / ISO C 中都是可用的。# 运算符会把 replacement - text 令牌转换为用引号引起来的字符串。
#define MKSTR( x ) #x<<"noneed"
//## 运算符用于连接两个令牌,将两个令牌拼接成一个变量名称，并解析出变量的值
#define CONCAT( x, y )  x ## y


inline int testPreDeal()
{
    int i, j;
    i = 100;
    j = 30;
    #ifdef DEBUG
        cerr << "Trace: Inside DEBUG function" << endl;
    #else
        cerr << "Trace: OutSide DEBUG function" << endl;
    #endif

    #if 0
        /* 这是注释部分 */
        cout << MKSTR(HELLO C++) << endl;
    #endif

        cout << "The minimum is " << MIN(i, j)<<endl;

    #ifdef DEBUG
        cerr << "Trace: Coming out of main function" << endl;
    #endif
        cout << MKSTR(HELLO C++) << endl;
        int xy = 100;
        int xyz = 10;
        cout << CONCAT(x,y) << endl;
        //cout << CONCAT(x,z)<< endl;  //没有xz变量

        cout << "Value of __LINE__ : " << __LINE__ << endl;
        cout << "Value of __FILE__ : " << __FILE__ << endl;
        cout << "Value of __DATE__ : " << __DATE__ << endl;
        cout << "Value of __TIME__ : " << __TIME__ << endl;
    return 0;
}


