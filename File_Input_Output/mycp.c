#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int rfd, wfd, n;
	char buf[BUFSIZ];
	
	if ((rfd = open(argv[1], O_RDONLY)) == -1) {
		perror("open");
		exit(1);
	}
	
	if ((wfd = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1) {
		perror("open");
		exit(1);
	}
	
	while ((n = read(rfd, buf, BUFSIZ)) > 0) {
		if (write(wfd, buf, n) != n) {
			perror("write");
			exit(1);
		}
	}

	if (n == -1) {
		perror("read");
		exit(1);
	}

	close(rfd);
	close(wfd);

	return 0;
}


