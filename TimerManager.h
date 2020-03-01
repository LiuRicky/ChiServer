#pragma once

#include <queue>
#include <vector>
#include <sys/time.h>
#include <unordered_map>
#include <memory>

typedef long long LL;

class Channel;
typedef std::shared_ptr<Channel> SP_Channel;

class TimerNode{
public:
    TimerNode(SP_Channel Channel, int timeout);
    ~TimerNode();
    LL getExpiredtime();
    void update(int timeout);
    bool isValib();
    bool isDeleted();
    SP_Channel getChannel();
private:
    SP_Channel channel;
    LL expiredtime;
};

typedef std::shared_ptr<TimerNode> SP_TimerNode;

struct TimerCmp{
    bool operator()(SP_TimerNode& a, SP_TimerNode& b){
        return a->getExpiredtime()>b->getExpiredtime();
    }
};

class TimerManager{
public:
    void addTimer(SP_Channel channel, int timeout);
    void handleExpiredEvent();
private:
    std::priority_queue<SP_TimerNode,
                            std::vector<SP_TimerNode>,
                            TimerCmp > timerheap;
    std::unordered_map<int,SP_TimerNode> timermap;                        
};

typedef std::shared_ptr<TimerManager> SP_TimerManager;