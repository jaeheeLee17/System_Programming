#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void) {
	DIR *dp;
	struct dirent *dent;
	struct stat sbuf;
	char *cwd;
	int kind;

	cwd = getcwd(NULL, BUFSIZ);
	printf("Current Directory : %s\n", cwd);
	if ((dp = opendir(cwd)) == NULL) {
		perror("opendir");
		exit(1);
	}

	while (dent = readdir(dp)) {
		stat(dent->d_name, &sbuf);
		kind = sbuf.st_mode & S_IFMT;
		switch (kind) {
			case S_IFDIR:
				printf("Directory : %s\n", dent->d_name);
				break;
			case S_IFREG:
				printf("File : %s\n", dent->d_name);
				break;
			default:
				printf("Unknown File\n");
				break;
		}
	}
	closedir(dp);
	return 0;
}
