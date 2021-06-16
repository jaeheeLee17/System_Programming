#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int hang = 1, i = 0,  n = 0;
	int fd;
	char buf[BUFSIZ];

	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		perror("open");
		exit(1);
	}

	printf("%d ", hang++);
	while ((n = read(fd, buf, BUFSIZ)) > 0 ) {
		for (i = 0; i < n; i++) {
			printf("%c", buf[i]);
			if (buf[i] == '\n') {
				printf("\n%d ", hang++);
			}
		}
	}
	printf("\n");
	
	return 0;
}

