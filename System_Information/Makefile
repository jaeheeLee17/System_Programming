CC=gcc
CFLAGS=-g -o
TARGETS=CheckUIDLength FileUIDGID LoginInfo mydate myuname PasswdChange SearchGroups
all:	$(TARGETS)
.PHONY: all
%:
	$(CC) $(CFLAGS) $@ $@.c
clean:
	rm $(TARGETS)
