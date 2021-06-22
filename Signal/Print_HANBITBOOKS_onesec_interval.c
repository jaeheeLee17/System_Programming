#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	sigset_t st;

	sigemptyset(&st);
	sigaddset(&st, SIGINT);
	sigprocmask(SIG_BLOCK, &st, (sigset_t *)NULL);

	while(1) {
		printf("Hanbit Books\n");
		sleep(1);
	}

	return 0;
}

