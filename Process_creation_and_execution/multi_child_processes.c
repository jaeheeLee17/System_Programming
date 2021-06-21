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
			switch (pid = fork()) {
				case -1:	/* fork failed */
					perror("fork");
					exit(1);
					break;
				case 0:		/* grand child process */
					printf("--> Grand_Child Process\n");
					exit(0);
					break;
				default:	/* parent process */
					while (wait(&status) != pid)
						continue;
					printf("--> Parent Process\n");
					printf("Child Process ID : %d\n", (int)pid);
			}
			exit(0);
			break;
		default:	/* grand parent process */
			while (wait(&status) != pid)
				continue;
			printf("--> Grand_Parent Process\n");
			printf("Child Process ID : %d\n", (int)pid);
	}

	return 0;
}

