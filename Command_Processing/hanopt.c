#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int n;
	extern char *optarg;
	
	n = getopt(argc, argv, "au:h");
	switch(n) {
		case 'a':
			printf("Welcome to Unix System Programming World!!!\n");
			break;
		case 'u':
			printf("Nice to meet %s\n", optarg);
			break;
		case 'h':
		default:
			printf("Option: \n");
			printf("\t-a : print \"Welcome to Unix System Programming World!!!\"\n");
			printf("\t-u [string] : print \"Nice to meet [string]\"\n");
			printf("\t-h : print Help Page\n");
		}
		return 0;
}
