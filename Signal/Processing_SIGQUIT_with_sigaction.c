#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int signo) {
	psignal(signo, "Received Signal: ");
	sleep(5);
	printf("In Signal Handler, After Sleep\n");
}

int main(void) {
	struct sigaction sigact;

	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = SA_RESETHAND;
	sigact.sa_handler = handler;

	if (sigaction(SIGQUIT, &sigact, (struct sigaction *)NULL) < 0) {
		perror("sigaction");
		exit(1);
	}

	fprintf(stderr, "Input SIGQUIT: ");
	pause();
	fprintf(stderr, "After Signal Handler\n");

	return 0;
}
