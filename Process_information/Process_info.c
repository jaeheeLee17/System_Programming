#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int pid;

	pid = atoi(argv[1]);

	if (pid == 0) {
		printf("PGID(0) : %d\n", (int)getpgid(0));
		printf("SID(0) : %d\n", (int)getsid(0));
	}
	else {
		printf("PGID(%d) : %d\n", pid, (int)getpgid(pid));
		printf("SID(%d) : %d\n", pid, (int)getsid(pid));
	}

	return 0;
}

