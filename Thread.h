#pragma once

#include "noncopyable.h"
#include <pthread.h>
#include <functional>
#include <memory>
#include <string>
#include <assert.h>
#include "MemoryPool.h"

typedef std::function<void()> ThreadFunc;

struct ThreadData{
    ThreadFunc func;
    std::string name;

    ThreadData(const ThreadFunc &Func, const std::string Name)
        : func(Func), name(Name){

    }

    void runInThread(){
        func();
    }
};

class Thread:noncopyable{
public:
    explicit Thread(const ThreadFunc&&, const std::string& name=std::string());
    ~Thread();
    void start();
    int join();
    bool started() const;
    const std::string& name() const;

private:
    void setDefaultName();
    bool started_;
    bool joined_;
    pthread_t pthreadId;
    ThreadFunc func;
    std::string name_;
};

typedef std::shared_ptr<Thread> SP_Thread;
typedef std::unique_ptr<Thread, decltype(deleteElement<Thread>)*> UP_Thread;
