#include "EventLoop.h"
#include "thread/thread.h"
#include <iostream>
using namespace std;

void threadFUnc()
{
	cout << "threadFunc(): pid = " << getpid() 
		<< ", tid = " << CurrentThread::tid() << endl;

	EventLoop loop;
	loop.loop();
}

int main()
{
	cout << "main(): pid = " << getpid() 
		<< ", tid = " CurrentThread::tid() << endl;

	EventLoop loop;

	Thread thread(threadFunc);
	thread.start();

	loop.loop();
	pthread_exit(NULL);
}