CC=gcc
CFLAGS=-g -o
TARGETS=DatafileMapping TruncateMapping MessageExchange
all:	$(TARGETS)
.PHONY: all
%:
	$(CC) $(CFLAGS) $@ $@.c
clean:
	rm $(TARGETS)

