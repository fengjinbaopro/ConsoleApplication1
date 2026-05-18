//所有的预处理器指令都是以井号（#）开头，只有空格字符可以出现在预处理指令之前。预处理指令不是 C++ 语句，所以它们不会以分号（; ）结尾。
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
#include "StaticTest.h"
#include "MemoryTest.h"
#include "OperatorTest.h"
#include "CastTest.h"
#include "JudgeMethodTest.h"
#include "ModifyTest.h"
#include "FileAndStream.h"
#include    "testException.h"
#include "ByteCommon.h"

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
    testException();
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
    //testAllKindsThreads();
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
    testStatic();
    testArray();
    testMemory();
    testOperatorPlus();
    testStaticCast();
    testDynamicCast();
    testSwitch();
    Example example;
    example.set_value(10);
    example.get_value();

    //testFileStream();
    testFileReadStream();
    testSet();
    testMap();
    testVecAndMat();

    cout << "main thread end " << endl;
    cin.get();
    return 0;
}
