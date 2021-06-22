#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(void) {
	sigset_t st;

	sigemptyset(&st);

	sigaddset(&st, SIGQUIT);
	sigaddset(&st, SIGILL);
	sigaddset(&st, SIGTRAP);

	if (sigismember(&st, SIGILL))
		printf("SIGILL is setting\n");

	// printf("Bit Pattern : %x\n", st.sig[0]);

	return 0;
}
