#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int pid;
	
	pid = atoi(argv[1]);
	printf("PGRP : %d\n", (int)getpgid(pid));
	
	return 0;
}
