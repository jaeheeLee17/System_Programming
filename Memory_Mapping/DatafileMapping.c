#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int fd;
	caddr_t addr;
	struct stat statbuf;

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

	addr = mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, fd, (off_t) 0);
	if (addr == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}

	if (mprotect(addr, statbuf.st_size, PROT_READ | PROT_WRITE)) {
		perror("mprotect");
		exit(1);
	}
	close(fd);
	
	printf("%s", addr);
	
	printf("---------\n");
	addr[0] = 'b';
	addr[1] = 'o';
	addr[2] = 'o';
	addr[3] = 'k';
	addr[4] = ' ';
	printf("%s\n", addr);

	msync(addr, statbuf.st_size, MS_SYNC);

	return 0;
}
