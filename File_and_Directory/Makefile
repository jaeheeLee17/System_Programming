CC=gcc
CFLAGS=-g -o
TARGETS=CheckFileType Create_MoveDir Erase_EmptyDir myls mymv mystat
all:	$(TARGETS)
.PHONY: all
%:
	$(CC) $(CFLAGS) $@ $@.c
clean:
	rm $(TARGETS)
