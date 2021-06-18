#include <shadow.h>
#include <time.h>
#include <stdio.h>

int main(void) {
	struct spwd *spw;
	struct tm *tm;
	time_t clock;
	char buf[257];

	spw = getspnam("syspro");
	clock = (time_t)(spw->sp_lstchg);
	tm = localtime(&clock);
	
	strftime(buf, sizeof(buf), "%G. %m. %d", tm);
	printf("%s's password last change : %s\n", spw->sp_namp, buf);

	return 0;
}



