GSTD := g++ -std=c++11
OPT := -lpthread

all:

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

.PHONY:clean
clean:
	rm *.o