#pragma once

#include "Packet.h"
#include <unordered_map>
#include <vector>
#include <memory>

#define MAXFDS 10000
#define EVENTS 4096
#define EPOLLWAIT_TIME -1

class Channel;
class Http_conn;
typedef std::shared_ptr<Channel> SP_Channel;

class Epoll{
public:
    Epoll();
    ~Epoll();
    void add(const SP_Channel& request);
    void update(const SP_Channel& request);
    void del(const SP_Channel& request);
    void poll(std::vector<SP_Channel>& req);
private:
    int epollfd;
    std::vector<SE> events;
    std::unordered_map<int,SP_Channel> Channelmap;
};