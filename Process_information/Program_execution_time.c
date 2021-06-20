#include <sys/types.h>
#include <sys/times.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int i, tot = 0;
	time_t t;
	struct tms mytms;
	clock_t t1, t2;

	if((t1 = times(&mytms)) == -1) {
		perror("times 1");
		exit(1);
	}

	for (i = 1; i < 10001; i++) {
		tot += i;
		printf("Total : %d\n", tot);
	}

	if ((t2 = times(&mytms)) == -1) {
		perror("times 2");
		exit(1);
	}

	printf("Execution Time : %.1f sec\n", (double)(t2 - t1) / _SC_CLK_TCK);

	return 0;
}
