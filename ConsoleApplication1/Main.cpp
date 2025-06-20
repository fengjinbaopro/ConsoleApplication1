//���е�Ԥ������ָ����Ծ��ţ�#����ͷ��ֻ�пո��ַ����Գ�����Ԥ����ָ��֮ǰ��Ԥ����ָ��� C++ ��䣬�������ǲ����Էֺţ�; ����β��
#include <iostream>
using namespace std;
#include "Exception.h"
#include    "Two.h"
#include "NameSpace.h"
#include "TemplateTest.h"
#include "PreDealTest.h"
#include "SignalTest.h"
#include "ThreadTest.h"
#include "WebApplyTest.h"
#include "STLMethodsTest.h"
#include "ConstructorTest.h"

int main()
{
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        z = division(x, y);
        cout << z << endl;
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }
    const int myint = 10;

    cout << "testException";
    first_space::func();
    MyNameSpace::Say();

    MyPrintSpace::Say();
    testStack();
    testMax();
    testPreDeal();
    ctrlCHandler();
    //testRaise(SIGINT);
    cout << "main thread testThreadsT1 begin " << endl;
    //testThreadsT1();
    //testThreadsT2();
    //testThreadT3();
    //testThreadRef();
    testAllKindsThreads();
    testAtomic();
    //testEnvironmet();
    testVectors();
    testAlgorithm();
    //testCinCout();
    //int testVariables();
    testVariables();
    testFileWriteStream();
    testFileWriteAppendStream();
    testFileReadStream();
    testContructor();

    cout << "main thread end " << endl;
    return 0;
}
