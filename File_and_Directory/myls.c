#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	DIR *dp;
	struct dirent *dent;
	struct stat sbuf;

	if ((dp = opendir(argv[1])) == NULL) {
		perror("opendir");
		exit(1);
	}

	while (dent = readdir(dp)) {
		if (dent->d_name[0] == '.')	continue;
		else {
			printf("%s  ", dent->d_name);
		}
	}
	printf("\n");
	closedir(dp);
	return 0;
}
