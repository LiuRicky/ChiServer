#pragma once

#include "Packet.h"
#include "Http_conn.h"
#include "EventLoop.h"
#include "ThreadpoolEventLoop.h"
#include "Logging.h"

class Http_conn{
public:
	Http_conn(SP_Channel channel);
	~Http_conn();
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