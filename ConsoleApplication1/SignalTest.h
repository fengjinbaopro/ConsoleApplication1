#pragma once
#include <iostream>
//#include <csignal>
//#include <unistd.h>
#include<signal.h >
using namespace std;

void signalHandler(int signum)
{
    cout << "Interrupt signal (" << signum << ") received.\n";

    // �����ر�
    // ��ֹ����  
    exit(signum);
}

int ctrlCHandler() {
    // ע���ź� SIGINT ���źŴ������
    signal(SIGINT, signalHandler);
    return 0;
}

int testRaise(int num) {
    int i = 0;
    while (++i) {
        if (i == 3) {
            cout << "raise(SIGINT)" << endl;
            cout << "ctrlCHandler��"<< ctrlCHandler << endl;
            raise(SIGINT);
        }
    }
    return 0;    
}