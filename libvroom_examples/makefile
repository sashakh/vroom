CXX ?= g++
CXXFLAGS = -I../src -std=c++14 -Wextra -Wpedantic -Wall -O3
LDLIBS = -L../lib/ -lvroom -lboost_system -lpthread

MAIN = ./libvroom-example
SRC = libvroom.cpp

all : $(MAIN)

$(MAIN) : $(SRC)
	$(CXX) $(CXXFLAGS) $^ $(LDLIBS) -o $@

clean :
	$(RM) $(MAIN)
