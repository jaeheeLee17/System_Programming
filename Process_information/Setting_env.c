#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	char *env_name;
	char *env_val;

	env_name = argv[1];
	env_val = argv[2];

	setenv(env_name, env_val, 1);
	
	env_val = getenv(env_name);

	if (env_val == NULL)
		printf("%s not defined\n", env_name);
	else
		printf("%s = %s\n", env_name, env_val);

	return 0;
}
