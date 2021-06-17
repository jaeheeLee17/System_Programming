#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

void CheckPermission(char *exp) {
	struct stat buf;
	stat(exp, &buf);

	printf("Before Access Permission : ");
	if ((buf.st_mode & S_IRUSR) != 0)       printf("r");
        else    printf("-");
        if ((buf.st_mode & S_IWUSR) != 0)       printf("w");
        else    printf("-");
        if ((buf.st_mode & S_IXUSR) != 0)       printf("x");
        else    printf("-");
        if ((buf.st_mode & S_IRGRP) != 0)       printf("r");
        else    printf("-");
        if ((buf.st_mode & S_IWGRP) != 0)       printf("w");
        else    printf("-");
        if ((buf.st_mode & S_IXGRP) != 0)       printf("x");
        else    printf("-");
        if ((buf.st_mode & S_IROTH) != 0)       printf("r");
        else    printf("-");
        if ((buf.st_mode & S_IWOTH) != 0)       printf("w");
        else    printf("-");
        if ((buf.st_mode & S_IXOTH) != 0)       printf("x\n");
        else    printf("-\n");
}

int main(int argc, char *argv[]) {
	struct stat buf;

	stat(argv[2], &buf);
	CheckPermission(argv[2]);

	if (argv[1][0] == 'u') {
		if (argv[1][1] == '+') {
			if (argv[1][2] == 'r')	buf.st_mode |= S_IRUSR;
			else if (argv[1][2] == 'w')	buf.st_mode |= S_IWUSR;
			else if (argv[1][2] == 'x')	buf.st_mode |= S_IXUSR;
		}
		else if (argv[1][1] == '-') {
			if (argv[1][2] == 'r')	buf.st_mode &= ~(S_IRUSR);
			else if (argv[1][2] == 'w')	buf.st_mode &= ~(S_IWUSR);
			else if (argv[1][2] == 'x')	buf.st_mode &= ~(S_IXUSR);
		}
		else	printf("Not + -. Try Again!\n");
	}
	else if (argv[1][0] == 'g') {
		if (argv[1][1] == '+') {
                        if (argv[1][2] == 'r')  buf.st_mode |= S_IRGRP;
                        else if (argv[1][2] == 'w')     buf.st_mode |= S_IWGRP;
                        else if (argv[1][2] == 'x')     buf.st_mode |= S_IXGRP;
                }
                else if (argv[1][1] == '-') {
                        if (argv[1][2] == 'r')  buf.st_mode &= ~(S_IRGRP);
                        else if (argv[1][2] == 'w')     buf.st_mode &= ~(S_IWGRP);
                        else if (argv[1][2] == 'x')     buf.st_mode &= ~(S_IXGRP);
                }
                else    printf("Not + -. Try Again!\n");
	}
	else if (argv[1][0] == 'o') {
		if (argv[1][1] == '+') {
                        if (argv[1][2] == 'r')  buf.st_mode |= S_IROTH;
                        else if (argv[1][2] == 'w')     buf.st_mode |= S_IWOTH;
                        else if (argv[1][2] == 'x')     buf.st_mode |= S_IXOTH;
                }
                else if (argv[1][1] == '-') {
                        if (argv[1][2] == 'r')  buf.st_mode &= ~(S_IROTH);
                        else if (argv[1][2] == 'w')     buf.st_mode &= ~(S_IWOTH);
                        else if (argv[1][2] == 'x')     buf.st_mode &= ~(S_IXOTH);
                }
                else    printf("Not + -. Try Again!\n");
	}
	chmod(argv[2], buf.st_mode);
	stat(argv[2], &buf);
	CheckPermission(argv[2]);
	
	return 0;
}

