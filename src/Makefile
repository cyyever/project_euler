SRCS=$(wildcard *.c) $(wildcard *.cpp)  
BINS=$(patsubst %.cpp,%,$(patsubst %.c,%,$(SRCS)))
CC=clang -std=c11
CXX=clang++ -std=c++11
CFLAGS=-O3 -Wall -Wextra -Werror -ferror-limit=1 -g -I/usr/local/include/my_math
CPPFLAGS=$(CFLAGS)
LDFLAGS=-lmy_math -L/usr/local/lib/my_math
.PHONY:all test clean install
all:$(BINS)
clean:
	-$(RM) $(BINS) *.o *~ 
