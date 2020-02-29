#include "Channel.h"
#include "EventLoop.h"
#include "Logging.h"

typedef std::shared_ptr<Channel> SP_Channel;

Channel::Channel(SP_EventLoop Loop)
:	loop(Loop),
	deleted(false),
	First(true)
{
	
}

Channel::~Channel(){
	LOG<<"delete fd="<<fd;
	Close(fd);
}

void Channel::setReadhandler(CallBack &&readHandler){
	readhandler=readHandler;
}

void Channel::setWritehandler(CallBack &&writeHandler){
	writehandler=writeHandler;
}

void Channel::setClosehandler(CallBack &&closeHandler){
	closehandler=closeHandler;
}

void Channel::setDeleted(bool Deleted){
	deleted=Deleted;
}

void Channel::handleEvent(){
	if(events&EPOLLIN)
		readhandler();
	else if(events&EPOLLOUT)
		writehandler();	
}

void Channel::handleClose(){
	closehandler();
}

void Channel::setnotFirst(){
	First=false;
}

void Channel::setFd(int Fd){
	fd=Fd;
}

void Channel::setRevents(int Revents){
	revents=Revents;
}

void Channel::setEvents(int Events){
	events=Events;
}

int Channel::getFd(){
	return fd;
}

int Channel::getRevents(){
	return revents; 
}

bool Channel::isDeleted(){
	return deleted;
}

bool Channel::isFirst(){
	return First;
}

WP_EventLoop Channel::getLoop(){
	return loop;
}