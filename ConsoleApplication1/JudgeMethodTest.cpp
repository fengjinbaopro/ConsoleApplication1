#include "JudgeMethodTest.h"

int testSwitch()
{
    // 局部变量声明
    char grade = 'D';

    switch (grade)
    {
    case 'A':
        cout << "很棒！" << endl;
        cout << "第二句话" << endl;
        break;
    case 'B':
    case 'C':
        cout << "做得好" << endl;
        cout << "第二句话" << endl;
        break;
    case 'D':
        cout << "您通过了" << endl;
        cout << "第二句话" << endl; 
        { //如果没有{}，会被跳过。
            JudgeMethodTest* a = new JudgeMethodTest();//“a”的初始化操作由“case”标签跳过
            a->say();
            int  d = 10;
            cout << "d:" << d << endl;
        }
        break;
    case 'F':
        cout << "最好再试一下" << endl;
        cout << "第二句话" << endl;
        break;
    default:
        cout << "无效的成绩" << endl;
    }
    cout << "您的成绩是 " << grade << endl;

    return 0;
}

void JudgeMethodTest::say()
{
    cout << "JudgeMethodTest say()" << endl;
}
