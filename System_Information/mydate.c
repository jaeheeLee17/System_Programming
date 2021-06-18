#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	struct tm *tm;
	time_t timestamp;
	char timebuf[257];
	int n;


	time(&timestamp);
	tm = localtime(&timestamp);
	n = getopt(argc, argv, "aymdwh");
	switch(n) {
		case 'a':
			strftime(timebuf, sizeof(timebuf), "%G. %m. %d. %w. %H:%M:%S", tm);
			printf("Present Date: %s\n", timebuf);
			break;
		case 'y':
			strftime(timebuf, sizeof(timebuf), "%G", tm);
			printf("Present Year: %s\n", timebuf);
			break;
		case 'm':
			strftime(timebuf, sizeof(timebuf), "%m", tm);
			printf("Present Month: %s\n", timebuf);
			break;
		case 'd':
			strftime(timebuf, sizeof(timebuf), "%d", tm);
			printf("Present Day: %s\n", timebuf);
			break;
		case 'w':
			strftime(timebuf, sizeof(timebuf), "%w", tm);
			printf("Present Weekday: %s\n", timebuf);
			break;
		case 'h':
			strftime(timebuf, sizeof(timebuf), "%H:%M:%S", tm);
			printf("Present Time: %s\n", timebuf);
			break;
		default:
			printf("This is not a correct option. Try again!\n");
			break;
	}
	return 0;
}
