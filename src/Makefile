SRCS=$(wildcard *.c) $(wildcard *.cpp)  
BINS=$(patsubst %.cpp,%,$(patsubst %.c,%,$(SRCS)))
CFLAGS=-O2 -Wall -Wextra -g -I/usr/local/include/my_math
CPPFLAGS=-O2 -Wall -Wextra -g -I/usr/local/include/my_math
LDFLAGS=-lmy_math -L/usr/local/lib/my_math
.PHONY:all test clean install
all:$(BINS)
clean:
	-$(RM) $(BINS) *.o *~ 
