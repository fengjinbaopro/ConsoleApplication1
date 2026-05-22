#ifndef THREAD_TEST_H
#define THREAD_TEST_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <queue>
using namespace std;


// ===================== 全局变量 仅声明！=====================
extern std::mutex mtx;
extern std::condition_variable cv;
extern bool ready;
extern std::atomic<int> global_count;
extern thread_local int threadData;

extern std::mutex dloack1; // 死锁用锁

// ===================== 函数声明 =====================
void printMessage(int count);
void testThreadsT1();
void testThreadsT2();
void testThreadT3();
int testThreadRef();

void foo(int Z);
int testAllKindsThreads();

void safeFunction();
int testMutex();
void safeFunctionWithLockGuard();
void safeFunctionWithUniqueLock();

void workerThread();
void mainThread();

void incrementAcomic();
int testAtomic();

void threadFunction();
int testThreadLocal();

void useLock1();
void useLock2();
void testUseLock();
void testDeadedLock();

int testConditionOpt();

int testReadWriteLock();

// ===================== 类声明 =====================
class PrintTask {
public:
    void operator()(int count) const;
};

class ThreadObj {
public:
    void operator()(int x) const;
};

#endif