#include "ThreadTest.h"
#include <string>
//ReadWrite

// ===================== 全局变量 真正定义（只在这里出现一次）=====================
std::mutex mtx;
queue<int> g_queue;          // 共享队列
std::condition_variable cv;
bool ready = false;
std::atomic<int> global_count(0);
thread_local int threadData = 0;
bool is_finished = false;    // 生产结束标记

std::mutex dloack1;
std::mutex dloack2;

mutex printMtx; // 打印专用锁

const int MAX_CAP = 5;
queue<int> dataQue;
condition_variable cvPro; // 生产者条件变量
condition_variable cvCon; // 消费者条件变量
bool exitFlag = false;

void safePrint(const string& str) {
    lock_guard<mutex> lock(printMtx); // 打印前加锁，保证不乱
    cout << str << endl;
}

// ===================== 下面是你所有函数实现 =====================
void printMessage(int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << "Hello from thread (function pointer)!\n";
    }
}

void PrintTask::operator()(int count) const {
    for (int i = 0; i < count; ++i) {
        std::cout << "Hello from thread (function object)!\n";
    }
}

void testThreadsT1() {
    std::thread t1(printMessage, 5);
    t1.join();
}

void testThreadsT2() {
    std::thread t2(PrintTask(), 5);
    t2.join();
}

void testThreadT3() {
    std::thread t3([](int count) {
        for (int i = 0; i < count; ++i) {
            std::cout << "Hello from thread (lambda)!\n";
        }
        }, 5);
    t3.join();
}

void increment(int& x) {
    ++x;
}

int testThreadRef() {
    int num = 0;
    std::thread t(increment, std::ref(num));
    t.join();
    std::cout << "Value after increment: " << num << std::endl;
    return 0;
}

void foo(int Z) {
    for (int i = 0; i < Z; i++) {
        std::cout << "线程使用函数指针作为可调用参数\n";
    }
}

void ThreadObj::operator()(int x) const {
    for (int i = 0; i < x; i++) {
        std::cout << "线程使用函数对象作为可调用参数\n";
    }
}

int testAllKindsThreads() {
    std::cout << "线程 1 、2 、3 独立运行" << std::endl;

    std::thread th1(foo, 3);
    std::thread th2(ThreadObj(), 3);
    std::thread th3([](int x) {
        for (int i = 0; i < x; i++) {
            std::cout << "线程使用 lambda 表达式作为可调用参数\n";
        }
        }, 3);

    th1.join();
    th2.join();
    th3.join();

    return 0;
}

void safeFunction() {
    mtx.lock();
    mtx.unlock();
}

int testMutex() {
    std::thread t1(safeFunction);
    std::thread t2(safeFunction);
    t1.join();
    t2.join();
    return 0;
}

void safeFunctionWithLockGuard() {
    std::lock_guard<std::mutex> lk(mtx);
}

void safeFunctionWithUniqueLock() {
    std::unique_lock<std::mutex> ul(mtx);
}

void workerThread() {
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk, [] { return ready; });
}

void mainThread() {
    {
        std::lock_guard<std::mutex> lk(mtx);
        ready = true;
    }
    cv.notify_one();
}

void incrementAcomic() {
    global_count.fetch_add(1, std::memory_order_relaxed);
}

int testAtomic() {
    std::thread t1(incrementAcomic);
    std::thread t2(incrementAcomic);
    t1.join();
    t2.join();
    return global_count;
}

void threadFunction() {
    threadData = 42;
    std::cout << "Thread data: " << threadData << std::endl;
}

int testThreadLocal() {
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);
    t1.join();
    t2.join();
    return 0;
}
//错误的死锁案例
void useLock1() {
    lock_guard<mutex>  lockg1(dloack1);
    cout << "线程" << this_thread::get_id() << "获得了lock1 等待获取lock2"<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    useLock2();
    cout << "线程1 同时拿到两把锁，执行任务" << endl;
}
//错误的死锁案例
void useLock2() {
    // 拿锁2
    std::lock_guard<std::mutex> lock2(dloack2);
    cout << "线程" << this_thread::get_id() << "获得了lock2 等待获取lock1"<<endl;
    this_thread::sleep_for(chrono::seconds(1));
   
    useLock1();
    cout << "线程"<< this_thread::get_id()<< "同时拿到两把锁，执行任务" << endl;
}
//两种结果
// 结果1，线程线程599882116获得了lock1 等待获取lock2获得了lock2 等待获取lock1
//cout 不是线程安全的！
//两个线程同时往屏幕打印，文字互相穿插、乱序拼接了。
//结果2，线程线程59260获得了lock2 等待获取lock1
//60020获得了lock1 等待获取lock2
void testUseLock() {
    thread t1(useLock1);
    thread t2(useLock2);
    //thread(useLock2).join();
    t1.join();
    t2.join();
}

//真正的死锁
void deadLock1() {
    lock_guard<mutex> lockg1(dloack1);
    cout<<"线程" << this_thread::get_id() << " 获得了lock1，等待lock2"<<endl;
    //safePrint("线程" + this_thread::get_id() + " 获得了lock1，等待lock2");

    this_thread::sleep_for(chrono::seconds(1));

    lock_guard<mutex> lockg2(dloack2);
    cout<<"线程" << this_thread::get_id() << " 拿到两把锁";
}
//真正的死锁
void deadLock2() {
    lock_guard<mutex> lockg2(dloack2);
    cout << "线程" << this_thread::get_id() << " 获得了lock2，等待lock1"<<endl;

    this_thread::sleep_for(chrono::seconds(1));

    lock_guard<mutex> lockg1(dloack1);
    cout << "线程" << this_thread::get_id() << " 拿到两把锁";
}
void testDeadedLock(){
    thread t1(useLock1);
    thread t2(useLock2);
    //thread(useLock2).join();
    t1.join();
    t2.join();
}
// 生产者
void producer()
{
    for (int i = 1; i <= 10; ++i)
    {
        unique_lock<mutex> lock(mtx);
        //cvCon.wait(lock, 条件);让出lock，本线程阻塞等待，直到条件满足，并且被唤醒。
        ////2. 阻塞等待
       //线程在这里睡觉，直到有人调用：
       //    cvCon.notify_one()
       ////    cvCon.notify_all()
       //3. 被唤醒后 → 重新 lock 锁
       //    醒来后自动重新上锁，然后检查谓词（lambda）：
       //    如果 返回 true → 醒了，继续往下走
       //    如果 返回 false → 继续睡，再解锁等待
        // 队列满则等待
        cvPro.wait(lock, []() { return dataQue.size() < MAX_CAP && !exitFlag; });

        dataQue.push(i);
        cout <<"线程：" << this_thread::get_id() << "生产数据：" << i << endl;

        cvCon.notify_one(); // 唤醒消费者
    }

    unique_lock<mutex> lock(mtx);
    exitFlag = true;
    cvCon.notify_all();
}
// 消费者
void consumer()
{
    while (true)
    {
        unique_lock<mutex> lock(mtx);
        // 队列为空且未结束，等待    //如果 返回 true → 醒了，继续往下走
        //如果 返回 false → 继续睡，再解锁等待
        ////1. 自动 unlock 锁 ,让出锁来给别的线程使用
        //wait 一进来，立刻把 lock 解开
        //    → 让别的线程能拿到锁、能生产、能修改数据
        ////2. 阻塞等待
        //线程在这里睡觉，直到有人调用：
        //    cvCon.notify_one()
        ////    cvCon.notify_all()
        //3. 被唤醒后 → 重新 lock 锁
        //    醒来后自动重新上锁，然后检查谓词（lambda）：
        //    如果 返回 true → 醒了，继续往下走
        //    如果 返回 false → 继续睡，再解锁等待
        cvCon.wait(lock, []() { return !dataQue.empty() || exitFlag; });

        if (exitFlag && dataQue.empty())
            break;

        int val = dataQue.front();
        dataQue.pop();
        cout << "消费数据：" << val << endl;

        cvPro.notify_one(); // 唤醒生产者
    }
}
int testConditionOpt()
{
    thread t1(producer);
    thread tp1(producer);
    thread t2(consumer);
    t1.join();
    tp1.join();
    t2.join();
    return 0;
}
