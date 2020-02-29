GSTD := g++ -std=c++11
OPT := -lpthread

test1:
	$(GSTD) test1.cpp ../Conf.o -o test $(OPT)

testlock:
	$(GSTD) -c testlock.cpp $(OPT)

.PHONY:clean
clean:
	rm test