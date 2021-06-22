#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void handler(int signo) {
	printf("Wake up\n");
}

int main(void) {
	sigset_t st;

	sigemptyset(&st);
	sigfillset(&st);
	sigdelset(&st, SIGINT);
	sigprocmask(SIG_BLOCK, &st, (sigset_t *)NULL);
	
	sigset(SIGALRM, handler);

	while(1) {
		alarm(1);
		sleep(1);
	}

	return 0;
}
