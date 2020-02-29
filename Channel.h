#pragma once

#include <functional>
#include <memory>
#include <sys/epoll.h>
#include "MemoryPool.h"

class EventLoop;
typedef std::shared_ptr<EventLoop> SP_EventLoop;
typedef std::weak_ptr<EventLoop> WP_EventLoop;
typedef std::function<void()> CallBack;

class Channel{
public:
    Channel(SP_EventLoop Loop);
    ~Channel();
    void setReadhandler(CallBack&& readhandler);
    void setWritehandler(CallBack &&writeHandler);
	void setClosehandler(CallBack &&closeHandler);
	void handleEvent();
	void handleClose();
    void setDeleted(bool Deleted);
    void setFd(int Fd);
	void setRevents(int Revents);
	void setEvents(int Events);
    void setnotFirst();
	bool isFirst();
	int getFd();
	int getRevents();
	bool isDeleted();
    WP_EventLoop getLoop();

private:
    int fd;
    int events; //want to do
    int revents;    //now doing
    bool deleted;
    bool First;
    WP_EventLoop loop;
    CallBack readhandler;
    CallBack writehandler;
	CallBack closehandler;
};