#pragma once

#include "Packet.h"
#include <unordered_map>
#include <memory>

class Http_conn;
class EventLoop;
class Channel;
class ThreadpoolEventLoop;
typedef std::shared_ptr<Http_conn> SP_Http_conn;
typedef std::shared_ptr<EventLoop> SP_EventLoop;
typedef std::shared_ptr<Channel> SP_Channel;
typedef std::unique_ptr<ThreadpoolEventLoop> UP_ThreadpoolEventLoop;

class Server{
public:
	Server(SP_Channel channel);
	~Server();
	void start();

private:
	SP_EventLoop loop;
	SP_Channel serverchannel;
	UP_ThreadpoolEventLoop iothreadpool;
	int listenfd;
	std::unordered_map<int, SP_Http_conn> Httpmap;
	void handleconn();
	void handleclose(WP_Channel channel);
	void deletemap(SP_Channel channel);

};