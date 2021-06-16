#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *rfp, *wfp;
	int n, cnt;
	char buf[BUFSIZ];

	if ((rfp = fopen(argv[1], "r")) == NULL) {
		perror("fopen");
		exit(1);
	}

	if ((wfp = fopen(argv[2], "w")) == NULL) {
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
	cnt = unlink(argv[1]);
	if (cnt == -1) {
		perror("unlink failed");
		exit(1);
	}

	fclose(rfp);
	fclose(wfp);

	return 0;
}
