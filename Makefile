STD := -std=c++11

all:
	g++ $(STD) -c Conf.cpp

.PHONY:clean
clean:
	rm *.o