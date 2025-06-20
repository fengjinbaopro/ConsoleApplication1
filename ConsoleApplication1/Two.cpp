#include <iostream>
#include <string>
#include "Two.h"
using namespace std;

void MyNameSpace::Say()

{
    cout << "MyNameSpace::Say()" << endl;
}

void MyPrintSpace::Say()
{
    cout << "MyPrintSpace::Say()" << endl;
}