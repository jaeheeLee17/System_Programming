CC=gcc
CFLAGS=-g -o
TARGETS=execute_who_with_execl execute_who_with_execvp Login_user_info multi_child_processes user_info_and_time wait_child_process_terminated_with_waitpid
all:	$(TARGETS)
.PHONY: all
%:
	$(CC) $(CFLAGS) $@ $@.c
clean:
	rm $(TARGETS)
