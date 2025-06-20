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
//���������������ʱ��Ƭ���ڽ���ִ�У����ֳ�ͬʱ���е�Ч����
//���У���������ڶ������������������ͬʱִ�С�
void printMessage(int count) {
    for (int i = 0; i <count; ++i) {
        std::cout << "Hello from thread (function pointer)!\n";
        //1 ���ʹ�� C++11 �����ϱ�׼���Ƽ�ʹ�� std::this_thread::sleep_for����Ҫ��������ͷ�ļ���
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        //2 ʹ�� Sleep() ������ע���д S������λΪ ���룬��Ҫ����
        //Sleep(1000);      // ��ͣ 3000 ���루�� 3 �룩
        //3 #include <unistd.h>
        //Linux / Unix / macOS ƽ̨ʹ�� sleep() ������Сд s������λΪ �룬��Ҫ����
    }
}
class PrintTask {
public:
    //״̬��װ:�����������Я���ڲ�״̬��ͨ����Ա������������ͨ��������ָ���޷�ֱ��ʵ�֡�
    void operator()(int count) const {
        for (int i = 0; i < count; ++i) {
            std::cout << "Hello from thread (function object)!\n";
        }
    }
};
//join() ���ڵȴ��߳����ִ�С���������� join() �� detach() ��ֱ�������̶߳��󣬻ᵼ�³��������
void testThreadsT1() {
    std::thread t1(printMessage, 5); // �����̣߳����ݺ���ָ��Ͳ���
    t1.join(); // join() ���ڵȴ��߳����ִ�С���������� join() �� detach() ��ֱ�������̶߳��󣬻ᵼ�³��������
}

void testThreadsT2() {
    std::thread t2(PrintTask(), 5); // �����̣߳����ݺ�������Ͳ���
    t2.join(); // �ȴ��߳����
    //detach() ���߳������̷߳��룬�߳��ں�̨�������У����̲߳��ٵȴ�����
}
void testThreadT3() {
    std::thread t3([](int count) {
        for (int i = 0; i < count; ++i) {
            std::cout << "Hello from thread (lambda)!\n";
        }
        }, 5); // �����̣߳����� Lambda ���ʽ�Ͳ���
    t3.join(); // �ȴ��߳����
}
//�����Ҫ�������ò�������Ҫʹ�� std::ref��
void increment(int& x) {
    ++x;
}
int testThreadRef() {
    int num = 0;
    std::thread t(increment, std::ref(num)); // ʹ�� std::ref ��������
    t.join();
    std::cout << "Value after increment: " << num << std::endl;
    return 0;
}

// һ���򵥵ĺ�������Ϊ�̵߳���ں���
void foo(int Z) {
    for (int i = 0; i < Z; i++) {
        cout << "�߳�ʹ�ú���ָ����Ϊ�ɵ��ò���\n";
    }
}

// �ɵ��ö�����ඨ��
class ThreadObj {
public:
    void operator()(int x) const {
        for (int i = 0; i < x; i++) {
            cout << "�߳�ʹ�ú���������Ϊ�ɵ��ò���\n";
        }
    }
};

int testAllKindsThreads() {
    cout << "�߳� 1 ��2 ��3 ��������" << endl;

    // ʹ�ú���ָ�봴���߳�
    thread th1(foo, 3);

    // ʹ�ú������󴴽��߳�
    thread th2(ThreadObj(), 3);

    // ʹ�� Lambda ���ʽ�����߳�
    thread th3([](int x) {
        for (int i = 0; i < x; i++) {
            cout << "�߳�ʹ�� lambda ���ʽ��Ϊ�ɵ��ò���\n";
        }
        }, 3);

    // �ȴ������߳����
    //th3.join(); // �ȴ��߳� th3 ���
    //th2.join(); // �ȴ��߳� th2 ���
    //th1.join(); // �ȴ��߳� th1 ���

    th1.join(); // �ȴ��߳� th3 ���
    th2.join(); // �ȴ��߳� th2 ���
    th3.join(); // �ȴ��߳� th1 ���
    //�����ʹ��join��������ô����˳�򽫻�������ġ�
    
    return 0;
}
//�߳�ͬ���뻥���������ǳ���Ҫ�ĸ���������ڿ��ƶ���̶߳Թ�����Դ�ķ��ʣ��Ա������ݾ��������������⡣

//1. ��������Mutex��
//��������һ��ͬ��ԭ����ڷ�ֹ����߳�ͬʱ���ʹ�����Դ����һ���߳���Ҫ���ʹ�����Դʱ����������Ҫ������lock����������
// ����������Ѿ��������߳���������ô�����������߳̽���������ֱ����������������unlock����
void safeFunction() {
    mtx.lock(); // ��������������
    // ���ʻ��޸Ĺ�����Դ
    mtx.unlock(); // �ͷŻ�����
}
int testMutex() {
    std::thread t1(safeFunction);
    std::thread t2(safeFunction);
    t1.join();
    t2.join();
    return 0;
}
//2. ����Locks��
//C++�ṩ�˶��������ͣ����ڼ򻯻�������ʹ�ú͹���
//�����������Ͱ�����
//std::lock_guard������������������ʱ�Զ�������������������ʱ�Զ�������
//std::unique_lock����std::lock_guard���ƣ����ṩ�˸��������ԣ��������ת������Ȩ���ֶ�������
void safeFunctionWithLockGuard() {
    std::lock_guard<std::mutex> lk(mtx);
    // ���ʻ��޸Ĺ�����Դ
}
void safeFunctionWithUniqueLock() {
    std::unique_lock<std::mutex> ul(mtx);
    // ���ʻ��޸Ĺ�����Դ
    // ul.unlock(); // ��ѡ���ֶ�����
    // ...
}
//3. ����������Condition Variable��
//�������������̼߳��Э��������һ�������̵߳ȴ�ĳ�������ķ�������ͨ���뻥����һ��ʹ�ã���ʵ���̼߳��ͬ����
//std::condition_variable����ʵ���̼߳�ĵȴ���֪ͨ���ơ�
std::condition_variable cv;
bool ready = false;

void workerThread() {
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk, [] { return ready; }); // �ȴ�����
    // ����������ʱִ�й���
}
void mainThread() {
    {
        std::lock_guard<std::mutex> lk(mtx);//std::lock_guard������������������ʱ�Զ�������������������ʱ�Զ�������
        // ׼������
        ready = true;
    } // �뿪������ʱ����
    cv.notify_one(); // ֪ͨһ���ȴ����߳�
}
//4. ԭ�Ӳ�����Atomic Operations��
//ԭ�Ӳ���ȷ���Թ������ݵķ����ǲ��ɷָ�ģ����ڶ��̻߳����£�ԭ�Ӳ���Ҫô��ȫִ�У�Ҫô��ȫ��ִ�У���������м�״̬��
std::atomic<int> global_count(0);

void incrementAcomic() {
    global_count.fetch_add(1, std::memory_order_relaxed);
}
int testAtomic() {
    std::thread t1(incrementAcomic);
    std::thread t2(incrementAcomic);
    t1.join();
    t2.join();
    return global_count; // Ӧ����2
}
//5. �ֲ߳̾��洢��Thread Local Storage, TLS��
//�ֲ߳̾��洢����ÿ���߳�ӵ���Լ������ݸ����������ͨ��thread_local�ؼ���ʵ�֣������˶Թ�����Դ�����á�
thread_local int threadData = 0;
void threadFunction() {
    threadData = 42; // ÿ���̶߳����Լ���threadData����
    std::cout << "Thread data: " << threadData << std::endl;
}
int testThreadLocal() {
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);
    t1.join();
    t2.join();
    return 0;
}
//6. ������Deadlock���ͱ������
//���������ڶ���̻߳���ȴ��Է��ͷ���Դ����û��һ���߳��ܹ�����ִ�С����������Ĳ��԰�����
//��������ͬ��˳��������Դ��
//ʹ�ó�ʱ�����Ի�ȡ��Դ��
//ʹ����������㷨��
//std::future �� std::promise��ʵ���̼߳��ֵ���ݡ�
//�̼߳�ͨ��
//std::future �� std::promise��ʵ���̼߳��ֵ���ݡ�
//std::promise<int> p;
//std::future<int> f = p.get_future();
//
//std::thread t([&p] {
//    p.set_value(10); // ����ֵ������ future
//    });
//
//int result = f.get(); // ��ȡֵ
//
//#include <algorithm>
//#include <vector>
// #include <execution>
//std::vector<int> vec = { 1, 2, 3, 4, 5 };
//std::for_each(std::execution::par, vec.begin(), vec.end(), [](int& n) {
//    n *= 2;
//});