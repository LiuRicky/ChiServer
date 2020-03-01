GSTD := g++ -std=c++11
OPT := -lpthread
OBJ := main.cpp Server.cpp Http_conn.cpp Mimetype.cpp Packet.cpp EventLoop.cpp Epoll.cpp Channel.cpp TimerManager.cpp Logging.cpp AsyncLogging.cpp LogStream.cpp LogFile.cpp FileUtil.cpp ThreadpoolEventLoop.cpp ThreadEventLoop.cpp Thread.cpp Conf.cpp MemoryPool.cpp LFUCache.cpp

all: 
	$(GSTD) $(OBJ) -o ChiServer $(OPT)

lfu: config memorypool
	$(GSTD) -c LFUCache.cpp $(OPT)

http: 
	$(GSTD) -c Http_conn.cpp $(OPT)

epoll: packet
	$(GSTD) -c Epoll.cpp $(OPT)

packet:
	$(GSTD) -c Packet.cpp $(OPT)

config:
	$(GSTD) -c Conf.cpp $(OPT)

memorypool:
	$(GSTD) -c MemoryPool.cpp $(OPT)

mimetype:
	$(GSTD) -c Mimetype.cpp $(OPT)

thread:
	$(GSTD) -c Thread.cpp $(OPT)

timer:
	$(GSTD) -c TimerManager.cpp $(OPT)

.PHONY:clean
clean:
	rm *.o