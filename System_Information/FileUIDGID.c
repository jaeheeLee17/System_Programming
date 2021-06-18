#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
	struct stat buf;
	struct passwd *upw;
	struct group *grp;

	stat(argv[1], &buf);

	upw = getpwuid((int)buf.st_uid);
	grp = getgrgid((int)buf.st_gid);
	printf("%s Owner: %s\n", argv[1], upw->pw_name);
	printf("%s Own Group: %s\n", argv[1], grp->gr_name);

	return 0;
}
