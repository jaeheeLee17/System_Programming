#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *rfp, *wfp;
	int n, cnt;
	char buf[BUFSIZ], wd[BUFSIZ];
	char *cwd, *path, *path2;

	cwd = getcwd(NULL, BUFSIZ);
	printf("Current Directory: %s\n", cwd);

	if ((rfp = fopen(argv[1], "r")) == NULL) {
		perror("fopen");
		exit(1);
	}

	chdir(argv[2]);
	getcwd(wd, BUFSIZ);
	printf("Current Directory: %s\n", wd);
	path = strcat(strcat(wd, "/"), argv[1]);

	if ((wfp = fopen(path, "w")) == NULL) {
		perror("fopen");
		exit(1);
	}

	while ((n = fread(buf, sizeof(char), BUFSIZ, rfp)) > 0) {
		if (fwrite(buf, sizeof(char), n, wfp) == -1) {
			perror("fwrite");
			exit(1);
		}
	}

	if (n == -1) {
		perror("fread");
		exit(1);
	}
	path2 = strcat(strcat(cwd, "/"), argv[1]);
	cnt = unlink(path2);
	if (cnt == -1) {
		perror("unlink failed");
		exit(1);
	}

	fclose(rfp);
	fclose(wfp);

	return 0;
}


