#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	DIR *dp;
	struct dirent *dent;

	if ((dp = opendir(argv[1])) == NULL) {
		perror("opendir");
		exit(1);
	}

	while ((dent = readdir(dp))) {
		if (dent->d_name[0] == '.')	continue;
		else	break;
	}

	if (dent == NULL) {
		printf("Directory is Empty!\n");
		if (rmdir(argv[1]) == -1) {
			perror("rmdir");
			exit(1);
		}
	} else {
		printf("Directory is not Empty!\n");
		printf("So you cannot erase!\n");
	}
	return 0;
}

