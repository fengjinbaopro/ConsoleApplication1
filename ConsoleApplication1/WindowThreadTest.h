#pragma once
//在Windows平台，Windows API提供了对多线程的支持。前面进程和线程的概念中我们提到，一个程序至少有一个线程，这个线程称为主线程(main thread)，如果我们不显示地创建线程，那我们产的程序就是只有主线程的间线程程序。
//https://www.runoob.com/w3cnote/cpp-multithread-demo.html
//#include "stdafx.h"
#include <windows.h>
#include <iostream>

using namespace std;

//线程函数
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    for (int i = 0; i < 5; ++i)
    {
        cout << "子线程:i = " << i << endl;
        Sleep(100);
    }
    return 0L;
}

int main()
{
    //创建一个线程
    HANDLE thread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    //关闭线程
    CloseHandle(thread);

    //主线程的执行路径
    for (int i = 0; i < 5; ++i)
    {
        cout << "主线程:i = " << i << endl;
        Sleep(100);
    }

    return 0;
}