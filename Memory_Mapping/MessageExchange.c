#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void sig_handler(int signo) {
	printf("Signal Handler Signal Number: %d\n", signo);
}

int main(int argc, char *argv[]) {
	int fd, status;
	pid_t pid;
	caddr_t addr;
	struct stat statbuf;
	void (*handling)(int);

	if (argc != 2) {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(1);
	}

	if (stat(argv[1], &statbuf) == -1) {
		perror("stat");
		exit(1);
	}

	if ((fd = open(argv[1], O_RDWR)) == -1) {
		perror("open");
		exit(1);
	}

	addr = mmap(NULL, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t) 0);
	if (addr == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}
	close(fd);

	handling = signal(SIGUSR1, sig_handler);
	if (handling == SIG_ERR) {
		perror("signal");
		exit(1);
	}

	switch(pid = fork()) {
		case -1:	/* fork failed */
			perror("fork");
			exit(1);
			break;
		case 0:		/* child process */
			strcpy(addr, "hello\n");
			kill(getppid(), SIGUSR1);
			break;
		default:	/* parent process */
			while (wait(&status) != pid)
				continue;
			printf("Child Process Message: %s\n", addr);
			break;
	}

	return 0;
}
