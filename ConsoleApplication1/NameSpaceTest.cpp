// NameSpaceTest.cpp£¨ÐÞÕýºó£©
#include <iostream>
#include "NameSpace.h"
#include "TemplateTest.h"
using namespace std;

namespace first_space {
    void func()
     { cout << "Inside first_space" << endl; }
}
 
void second_space::func() {
      { cout << "Inside second_space" << endl; }
}

void testMax1() {
    int i = 39;
    int j = 20;
    Max(i, j);
}
