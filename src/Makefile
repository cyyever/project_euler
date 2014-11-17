SRCS=$(wildcard *.c)
BINS=$(patsubst %.c,%,$(SRCS))
DEPS=$(patsubst %.c,%.d,$(SRCS))
OBJS=$(patsubst %.c,%.o,$(SRCS))
CC=gcc
CFLAGS=-O2 -Wall -g -I/usr/local/include/my_math
LDFLAGS=-lmy_math -L/usr/local/lib/my_math
.PHONY:all test clean install
all:
	-make $(BINS)
	-$(RM) $(DEPS) $(OBJS)
%:%.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)
clean:
	-$(RM) $(BINS) $(OBJS) $(DEPS) *~ 
	clear
%.d: %.c 
	@set -e; rm -f $@; \
	$(CC) -M $(CFLAGS) $< | sed 's,\($(notdir $*)\)\.o[ :]*,$(dir $*)\1.o $@ : ,g' > $@; 
	-include $(DEPS)
