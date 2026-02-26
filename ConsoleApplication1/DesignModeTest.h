#pragma once
#include "CommonInclude.h"
class DesignModeTest
{

};

class Singleton {
private:
    static Singleton* instance;
    Singleton() {}
public:
    static Singleton* getInstance() {
        if (!instance)
            instance = new Singleton();
        return instance;
    }
};
class Product {
public:
    virtual void use() = 0;
};

class ConcreteProduct : public Product {
public:
    void use() override { /*...*/ }
};

class Factory {
public:
    virtual Product* createProduct() = 0;
};

class ConcreteFactory : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProduct();
    }
};

class Observer {
public:
    virtual void update() = 0;
};

class Subject {
    vector<Observer*> observers;
public:
    void attach(Observer* o) { observers.push_back(o); }
    void notify() {
        for (auto o : observers) o->update();
    }
};

//class Singleton {
//private:
//    static std::atomic<Singleton*> instance;
//    static std::mutex mtx;
//    Singleton() {}
//
//public:
//    Singleton(const Singleton&) = delete;
//    Singleton& operator=(const Singleton&) = delete;
//
//    static Singleton* getInstance() {
//        Singleton* tmp = instance.load(std::memory_order_relaxed);
//        std::atomic_thread_fence(std::memory_order_acquire);
//        if (tmp == nullptr) {
//            std::lock_guard<std::mutex> lock(mtx);
//            tmp = instance.load(std::memory_order_relaxed);
//            if (tmp == nullptr) {
//                tmp = new Singleton();
//                std::atomic_thread_fence(std::memory_order_release);
//                instance.store(tmp, std::memory_order_relaxed);
//            }
//        }
//        return tmp;
//    }
//}; 