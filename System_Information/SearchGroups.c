#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUF_SIZE 40

int main(void) {
	struct passwd *pw;
	struct group *prim_grp, *secondary_grp;

	pw = getpwnam("syspro");
	prim_grp = getgrgid(pw->pw_gid);
	printf("Primary Group\n%s\n", prim_grp->gr_name);
	printf("\n");
	
	printf("Secondary Groups\n");
	while ((secondary_grp = getgrent()) != NULL) {
		int m_idx = 0;
		while (secondary_grp->gr_mem[m_idx] != NULL) {
			if (strcmp(secondary_grp->gr_mem[m_idx], pw->pw_name) == 0) {
				printf("%s ", secondary_grp->gr_name);
				printf("\n");
			}
			m_idx++;
		}
	}

	return 0;
}

