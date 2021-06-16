#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FILE *fp;
	char buf[50];
	char *fname;

	fname = tempnam("./", "tmp");
	if ((fp = fopen(fname, "w")) == NULL) {
		perror("fopen");
		exit(1);
	}

	printf("temp file name : %s\n", fname);
	fprintf(fp, "%d %s\n", 2017012406, "Jae Hee Lee");

	fclose(fp);
	return 0;
}
