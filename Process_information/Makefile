CC=gcc
CFLAGS=-g -o
TARGETS=Control_hbenv Execution_time_with_sleep Get_pgid Process_info Program_execution_time Setting_env
all:	$(TARGETS)
.PHONY: all
%:
	$(CC) $(CFLAGS) $@ $@.c
clean:
	rm $(TARGETS)
