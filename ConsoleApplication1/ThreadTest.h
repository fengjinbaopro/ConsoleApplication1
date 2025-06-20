#pragma once
#include "StringTest.h"
#include <thread>
#include <chrono>
#include <Windows.h>
#include <mutex>
#include <atomic>
using namespace std;
std::mutex mtx;

//#include <unistd.h>
//并发：多个任务在时间片段内交替执行，表现出同时进行的效果。
//并行：多个任务在多个处理器或处理器核上同时执行。
void printMessage(int count) {
    for (int i = 0; i <count; ++i) {
        std::cout << "Hello from thread (function pointer)!\n";
        //1 如果使用 C++11 及以上标准，推荐使用 std::this_thread::sleep_for，需要包含以下头文件：
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        //2 使用 Sleep() 函数（注意大写 S），单位为 毫秒，需要包含
        //Sleep(1000);      // 暂停 3000 毫秒（即 3 秒）
        //3 #include <unistd.h>
        //Linux / Unix / macOS 平台使用 sleep() 函数（小写 s），单位为 秒，需要包含
    }
}
class PrintTask {
public:
    //状态封装:函数对象可以携带内部状态（通过成员变量），而普通函数或函数指针无法直接实现。
    void operator()(int count) const {
        for (int i = 0; i < count; ++i) {
            std::cout << "Hello from thread (function object)!\n";
        }
    }
};
//join() 用于等待线程完成执行。如果不调用 join() 或 detach() 而直接销毁线程对象，会导致程序崩溃。
void testThreadsT1() {
    std::thread t1(printMessage, 5); // 创建线程，传递函数指针和参数
    t1.join(); // join() 用于等待线程完成执行。如果不调用 join() 或 detach() 而直接销毁线程对象，会导致程序崩溃。
}

void testThreadsT2() {
    std::thread t2(PrintTask(), 5); // 创建线程，传递函数对象和参数
    t2.join(); // 等待线程完成
    //detach() 将线程与主线程分离，线程在后台独立运行，主线程不再等待它。
}
void testThreadT3() {
    std::thread t3([](int count) {
        for (int i = 0; i < count; ++i) {
            std::cout << "Hello from thread (lambda)!\n";
        }
        }, 5); // 创建线程，传递 Lambda 表达式和参数
    t3.join(); // 等待线程完成
}
//如果需要传递引用参数，需要使用 std::ref：
void increment(int& x) {
    ++x;
}
int testThreadRef() {
    int num = 0;
    std::thread t(increment, std::ref(num)); // 使用 std::ref 传递引用
    t.join();
    std::cout << "Value after increment: " << num << std::endl;
    return 0;
}

// 一个简单的函数，作为线程的入口函数
void foo(int Z) {
    for (int i = 0; i < Z; i++) {
        cout << "线程使用函数指针作为可调用参数\n";
    }
}

// 可调用对象的类定义
class ThreadObj {
public:
    void operator()(int x) const {
        for (int i = 0; i < x; i++) {
            cout << "线程使用函数对象作为可调用参数\n";
        }
    }
};

int testAllKindsThreads() {
    cout << "线程 1 、2 、3 独立运行" << endl;

    // 使用函数指针创建线程
    thread th1(foo, 3);

    // 使用函数对象创建线程
    thread th2(ThreadObj(), 3);

    // 使用 Lambda 表达式创建线程
    thread th3([](int x) {
        for (int i = 0; i < x; i++) {
            cout << "线程使用 lambda 表达式作为可调用参数\n";
        }
        }, 3);

    // 等待所有线程完成
    //th3.join(); // 等待线程 th3 完成
    //th2.join(); // 等待线程 th2 完成
    //th1.join(); // 等待线程 th1 完成

    th1.join(); // 等待线程 th3 完成
    th2.join(); // 等待线程 th2 完成
    th3.join(); // 等待线程 th1 完成
    //如果不使用join函数，那么运行顺序将会是随机的。
    
    return 0;
}
//线程同步与互斥是两个非常重要的概念，它们用于控制多个线程对共享资源的访问，以避免数据竞争、死锁等问题。

//1. 互斥量（Mutex）
//互斥量是一种同步原语，用于防止多个线程同时访问共享资源。当一个线程需要访问共享资源时，它首先需要锁定（lock）互斥量。
// 如果互斥量已经被其他线程锁定，那么请求锁定的线程将被阻塞，直到互斥量被解锁（unlock）。
void safeFunction() {
    mtx.lock(); // 请求锁定互斥量
    // 访问或修改共享资源
    mtx.unlock(); // 释放互斥量
}
int testMutex() {
    std::thread t1(safeFunction);
    std::thread t2(safeFunction);
    t1.join();
    t2.join();
    return 0;
}
//2. 锁（Locks）
//C++提供了多种锁类型，用于简化互斥量的使用和管理。
//常见的锁类型包括：
//std::lock_guard：作用域锁，当构造时自动锁定互斥量，当析构时自动解锁。
//std::unique_lock：与std::lock_guard类似，但提供了更多的灵活性，例如可以转移所有权和手动解锁。
void safeFunctionWithLockGuard() {
    std::lock_guard<std::mutex> lk(mtx);
    // 访问或修改共享资源
}
void safeFunctionWithUniqueLock() {
    std::unique_lock<std::mutex> ul(mtx);
    // 访问或修改共享资源
    // ul.unlock(); // 可选：手动解锁
    // ...
}
//3. 条件变量（Condition Variable）
//条件变量用于线程间的协调，允许一个或多个线程等待某个条件的发生。它通常与互斥量一起使用，以实现线程间的同步。
//std::condition_variable用于实现线程间的等待和通知机制。
std::condition_variable cv;
bool ready = false;

void workerThread() {
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk, [] { return ready; }); // 等待条件
    // 当条件满足时执行工作
}
void mainThread() {
    {
        std::lock_guard<std::mutex> lk(mtx);//std::lock_guard：作用域锁，当构造时自动锁定互斥量，当析构时自动解锁。
        // 准备数据
        ready = true;
    } // 离开作用域时解锁
    cv.notify_one(); // 通知一个等待的线程
}
//4. 原子操作（Atomic Operations）
//原子操作确保对共享数据的访问是不可分割的，即在多线程环境下，原子操作要么完全执行，要么完全不执行，不会出现中间状态。
std::atomic<int> global_count(0);

void incrementAcomic() {
    global_count.fetch_add(1, std::memory_order_relaxed);
}
int testAtomic() {
    std::thread t1(incrementAcomic);
    std::thread t2(incrementAcomic);
    t1.join();
    t2.join();
    return global_count; // 应返回2
}
//5. 线程局部存储（Thread Local Storage, TLS）
//线程局部存储允许每个线程拥有自己的数据副本。这可以通过thread_local关键字实现，避免了对共享资源的争用。
thread_local int threadData = 0;
void threadFunction() {
    threadData = 42; // 每个线程都有自己的threadData副本
    std::cout << "Thread data: " << threadData << std::endl;
}
int testThreadLocal() {
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);
    t1.join();
    t2.join();
    return 0;
}
//6. 死锁（Deadlock）和避免策略
//死锁发生在多个线程互相等待对方释放资源，但没有一个线程能够继续执行。避免死锁的策略包括：
//总是以相同的顺序请求资源。
//使用超时来尝试获取资源。
//使用死锁检测算法。
//std::future 和 std::promise：实现线程间的值传递。
//线程间通信
//std::future 和 std::promise：实现线程间的值传递。
//std::promise<int> p;
//std::future<int> f = p.get_future();
//
//std::thread t([&p] {
//    p.set_value(10); // 设置值，触发 future
//    });
//
//int result = f.get(); // 获取值
//
//#include <algorithm>
//#include <vector>
// #include <execution>
//std::vector<int> vec = { 1, 2, 3, 4, 5 };
//std::for_each(std::execution::par, vec.begin(), vec.end(), [](int& n) {
//    n *= 2;
//});