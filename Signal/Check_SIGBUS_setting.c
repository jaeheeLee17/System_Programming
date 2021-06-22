#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(void) {
	sigset_t st;

	sigemptyset(&st);
	sigfillset(&st);

	if (sigismember(&st, SIGBUS))
		printf("SIGBUS is setting\n");

	return 0;
}
