#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int ans = system("who > LoginUser.txt");
	printf("Return Value : %d\n", ans);

	return 0;
}
