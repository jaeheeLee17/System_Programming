#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	struct utsname uts;
	int n;

	if (uname(&uts) == -1) {
		perror("uname");
		exit(1);
	}

	n = getopt(argc, argv, "asnrvm");
	switch(n) {
		case 'a':
			printf("OSname : %s\n", uts.sysname);
			printf("Nodename : %s\n", uts.nodename);
			printf("Release : %s\n", uts.release);
			printf("Version : %s\n", uts.version);
			printf("Machine : %s\n", uts.machine);
			break;
		case 's':
			printf("OSname : %s\n", uts.sysname);
			break;
		case 'n':
			printf("Nodename : %s\n", uts.nodename);
			break;
		case 'r':
			printf("Release : %s\n", uts.release);
			break;
		case 'v':
			printf("Version : %s\n", uts.version);
			break;
		case 'm':
			printf("Machine : %s\n", uts.machine);
			break;
		default:
			printf("This is not a correct option. Try again!");
			break;
		}
		return 0;
}

