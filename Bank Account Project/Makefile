CXX = g++
CXXFLAGS = -Wall -g -std=c++11

all: fss_test

fss_test: test.cpp Financial/*.cpp Financial/*.hpp
	$(CXX) $(CXXFLAGS) -o fss_test $^

test: fss_test
	./fss_test

clean:
	rm -f fss_test
