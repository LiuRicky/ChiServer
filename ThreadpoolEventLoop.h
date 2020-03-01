#pragma once 

#include "ThreadEventLoop.h"

typedef std::shared_ptr<ThreadEventLoop> SP_ThreadEventLoop;
typedef std::shared_ptr<EventLoop> SP_EventLoop;

class ThreadpoolEventLoop{
public:
    ThreadpoolEventLoop(int Threadnum);
	~ThreadpoolEventLoop();
	void start();
	SP_EventLoop getNextloop();

private:
    std::vector<SP_ThreadEventLoop> elv;	
	int threadnum;	
	int index;
};