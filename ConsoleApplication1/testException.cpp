#include <iostream>
using namespace std;

double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a / b);
    {
    }
}
class MyExcepiton :std::exception {
public:
    const char* what() const throw ()
    {
        return "C++ Exception";
    }
};
class MyBadAllocException :std::bad_alloc {
public:
    const char* what() const throw ()
    {
        return "C++ Exception";
    }
};
void testException() {
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
    catch (...) {//处理程序屏蔽默认处理程序
        cerr << "catched by ..." << endl;
    }
    
   
}
