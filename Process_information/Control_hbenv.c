#include <stdlib.h>
#include <stdio.h>

int main(void) {
	char *val;

	setenv("HBENV", "hbooks", 1);

	val = getenv("HBENV");

	if (val == NULL)
		printf("HBENV not defined\n");
	else
		printf("HBENV = %s\n", val);
	
	unsetenv("HBENV");

	val = getenv("HBENV");

	if (val == NULL)
		printf("HBENV not defined\n");
	else
		printf("HBENV = %s\n", val);

	return 0;
}

