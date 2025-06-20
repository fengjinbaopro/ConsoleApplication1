#pragma once
#include <iostream>
using namespace std;
#define MIN(a,b) (((a)<(b)) ? a : b)
#define DEBUG
//# �� ## Ԥ����������� C++ �� ANSI / ISO C �ж��ǿ��õġ�# �������� replacement - text ����ת��Ϊ���������������ַ�����
#define MKSTR( x ) #x<<"noneed"
//## ���������������������,����������ƴ�ӳ�һ���������ƣ���������������ֵ
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
        /* ����ע�Ͳ��� */
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
        //cout << CONCAT(x,z)<< endl;  //û��xz����

        cout << "Value of __LINE__ : " << __LINE__ << endl;
        cout << "Value of __FILE__ : " << __FILE__ << endl;
        cout << "Value of __DATE__ : " << __DATE__ << endl;
        cout << "Value of __TIME__ : " << __TIME__ << endl;
    return 0;
}


