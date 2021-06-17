#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	char *cwd;
	char wd[BUFSIZ];
	
	if (mkdir(argv[1], 0755) == -1) {
		perror("mkdir");
		exit(1);
	}

	cwd = getcwd(NULL, BUFSIZ);
	printf("1. Current Working Directory : %s\n", cwd);

	chdir(argv[1]);

	cwd = getcwd(wd, BUFSIZ);
	printf("2. Current Working Directory : %s\n", wd);

	return 0;
}
