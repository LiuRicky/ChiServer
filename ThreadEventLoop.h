#pragma once

#include <vector>
#include <memory>

class EventLoop;
class Thread;
typedef std::shared_ptr<EventLoop> SP_Eventloop;
typedef std::unique_ptr<Thread> UP_Thread;

class ThreadEventLoop{
public:
    ThreadEventLoop();
    ~ThreadEventLoop();
    void start();
    SP_EventLoop getLoop();
    
private:
    SP_EventLoop loop;
    UP_Thread thread;
    void Loop();
};