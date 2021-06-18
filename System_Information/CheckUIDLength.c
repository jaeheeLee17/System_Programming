#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define ID_length 1024

int main(void) {
	char *userid;
	int max_id_length;

	userid = (char *)malloc(sizeof(char) * ID_length);
	fgets(userid, ID_length, stdin);
	max_id_length = sysconf(_SC_LOGIN_NAME_MAX);

	if (strlen(userid) > max_id_length) {
		printf("Your ID is longer than max_id_length!\n");
	} else {
		printf("Your ID is shorter than max_id_length!\n");
	}

	free(userid);
	return 0;
}
