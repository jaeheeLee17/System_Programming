#include <sys/types.h>
#include <utmpx.h>
#include <stdio.h>
#include <time.h>

int main(void) {
	struct utmpx *wpx;
	struct tm *tm;
	time_t timestamp;
	char ct[257];

	printf("LoginName Line LogoutTime RemoteAccess\n");
	printf("--------------------------------------\n");

	while ((wpx = getutxent()) != NULL) {
		if (wpx->ut_type != USER_PROCESS) {
			continue;
		}

		if (wpx->ut_type == DEAD_PROCESS) {
			timestamp = wpx->ut_tv.tv_sec;
			tm = localtime(&timestamp);
			strftime(ct, sizeof(ct), "%G. %m. %d. %H:%M:%S", tm);
		}

		printf("%s\t%s\t%s\t%s\n", wpx->ut_user, wpx->ut_line, ct, wpx->ut_host);
	}
	return 0;
}
