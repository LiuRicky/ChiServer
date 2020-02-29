#pragma once

#include <functional>
#include <memory>
#include <sys/epoll.h>
#include "MemoryPool.h"

class EventLoop;
typedef std::shared_ptr<EventLoop> SP_EventLoop;
typedef std::weak_ptr<EventLoop> WP_EventLoop;

class Channel{
public:
    Channel(SP_EventLoop Loop);
    ~Channel();

};