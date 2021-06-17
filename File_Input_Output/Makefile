CC=gcc
CFLAGS=-g -o
TARGETS=datafileread dataread grading mycat mycp mymv student_info
all:	$(TARGETS)
.PHONY: all
%:
	$(CC) $(CFLAGS) $@ $@.c
clean:
	rm $(TARGETS)
