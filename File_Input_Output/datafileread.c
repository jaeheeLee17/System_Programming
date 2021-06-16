#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FILE *rfp, *wfp;
	int n;
	long cur;
	char buf[BUFSIZ];

	if ((rfp = fopen("data.txt", "r")) == NULL) {
		perror("fopen: data.txt");
		exit(1);
	}

	if ((wfp = fopen("data.out", "w")) == NULL) {
		perror("fopen: data.out");
		exit(1);
	}

	while ((n = fread(buf, sizeof(char), 1, rfp)) > 0) {
		cur = ftell(rfp);
		if (cur % 2 != 0) {
			fwrite(buf, sizeof(char), 1, wfp);
		}
	}
	buf[n] = '\0';
	fclose(rfp);
	fclose(wfp);

	return 0;
}
