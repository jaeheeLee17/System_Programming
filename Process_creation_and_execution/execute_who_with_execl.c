#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int status;
	pid_t pid;

	switch (pid = fork()) {
		case -1:	/* fork failed */
			perror("fork");
			exit(1);
			break;
		case 0:		/* child process */
			printf("--> Child Process\n");
			if (execl("/usr/bin/who", "who", (char *)NULL) == -1) {
				perror("execl");
				exit(2);
			}
			exit(0);
			break;
		default:	/* parent process */
			while (wait(&status) != pid)
				continue;
			printf("--> Parent Process\n");
	}

	return 0;
}
