#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int fd, n;
	off_t start, cur;
	char buf[BUFSIZ];

	if ((fd = open("data.txt", O_RDONLY)) == -1) {
		perror("open");
		exit(1);
	}

	start = lseek(fd, 0, SEEK_CUR);
	while ((n = read(fd, buf, 1)) > 0) {
		cur = lseek(fd, 0, SEEK_CUR);
		if (cur % 2 != 0) {
			printf("%s", buf);
		}
	}
	buf[n] = '\0';
	close(fd);

	return 0;
}
