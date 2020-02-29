#include "Server.h"

Server::Server(const char* port, int threadnum)
	: loop(newElement<EventLoop>(), deleteElement<EventLoop>),
	  serverchannel(newElement<Channel>(loop), deleteElement<Channel>),
	  iothreadpool(newElement<threadpoolEventLoop>(threadnum),
	  	deleteElement<threadpoolEventLoop>)
{
	listenfd = tcp_listen(NULL, port, NULL);
	setnonblocking(listenfd);
	serverchannel->setFd(listenfd);
}

Server::~Server(){
	Close(listenfd);
}

void Server::start(){
	iothreadpool->start();
	serverchannel->setRevents(EPOLLIN | EPOLLET);
	serverchannel->setReadHandler(bind(&Server::handleconn, this));
	loop->addPoller(serverchannel);
	LOG << "Start";
	loop->loop();
}

void Server::handleconn(){
	struct sockaddr_storage cliaddr;
	socklen_t clilen = sizeof(cliaddr);
	int connfd;
	while( (connfd = Accept(listenfd, (SA*)& cliaddr, &clilen) ) >= 0){
		LOG << "Accept Fd = " << connfd;
		setnonblocking(connfd);
		SP_EventLoop nextloop = iothreadpool->getNextloop();
		SP_Channel connchannel(newElement<Channel>(nextloop), 
			deleteElement<Channel>);
		connchannel->setFd(connfd);
		WP_Channel wpchannel = connchannel;
		connchannel->setClosehandler(bind(&Server::handleclose, this, wpchannel));
		
		connchannel->setRevents(EPOLLIN | EPOLLET);
		SP_Http_conn connhttp(newElement<Http_conn>(connchannel), 
			deleteElement<Http_conn>())
		Httpmap[connfd] = move(connhttp);

		nextloop->queueInLoop(bind(&EventLoop::addPoller, nextloop,
			move(connchannel)));
	}
}

void Server::handleclose(WP_Channel channel){
	SP_Channel spchannel = channel.lock();
	loop->queueInLoop(bind(&Server::deletemap, this, spchannel));
	spchannel->getLoop().lock()->removePoller(spchannel);
}

void Server::deletemap(SP_Channel channel){
	Httpmap.erase(channel->getFd());
}
