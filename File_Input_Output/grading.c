#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int fd, n, i = 0, k = 0;
	int g[4];
	int id;
	char buf[10];
	char ch;

	if ((fd = open("grade.txt", O_RDONLY)) == -1) {
		perror("open grade.txt");
		exit(1);
	}

	printf("student_id	average\n");
	while ((n = read(fd, &ch, 1)) > 0) {
		if (ch == ' ' || ch == '\n') {
			buf[k] = '\0';
			g[i++] = atoi(buf);
			k = 0;
			if (ch == '\n') {
				printf("%d		%d\n", g[0], ((g[1] + g[2] + g[3]) / 3));
				i = 0;
			}
		} else {
			buf[k++] = ch;
		}
	}
	close(fd);
	return 0;
}
