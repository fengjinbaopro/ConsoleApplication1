#pragma once
//��Windowsƽ̨��Windows API�ṩ�˶Զ��̵߳�֧�֡�ǰ����̺��̵߳ĸ����������ᵽ��һ������������һ���̣߳�����̳߳�Ϊ���߳�(main thread)��������ǲ���ʾ�ش����̣߳������ǲ��ĳ������ֻ�����̵߳ļ��̳߳���
//https://www.runoob.com/w3cnote/cpp-multithread-demo.html
//#include "stdafx.h"
#include <windows.h>
#include <iostream>

using namespace std;

//�̺߳���
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    for (int i = 0; i < 5; ++i)
    {
        cout << "���߳�:i = " << i << endl;
        Sleep(100);
    }
    return 0L;
}

int main()
{
    //����һ���߳�
    HANDLE thread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    //�ر��߳�
    CloseHandle(thread);

    //���̵߳�ִ��·��
    for (int i = 0; i < 5; ++i)
    {
        cout << "���߳�:i = " << i << endl;
        Sleep(100);
    }

    return 0;
}