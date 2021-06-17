#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

void CheckPermission(char *exp) {
	struct stat buf;
	stat(exp, &buf);

	printf("Access Permission : ");

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
        else	printf("-\n");
}

int main(int argc, char *argv[]) {
	struct stat buf;

	stat(argv[2], &buf);
	CheckPermission(argv[2]);
	int i = 1, x = 0;
	while (i < 4) {
		x = 0;
		switch(argv[1][i]) {
			case '7':
				x |= S_IRWXU;
				break;
			case '6':
				x |= (S_IRUSR | S_IWUSR);
				break;
			case '5':
				x |= (S_IRUSR | S_IXUSR);
				break;
			case '4':
				x |= S_IRUSR;
				break;
			case '3':
				x |= (S_IWUSR | S_IXUSR);
				break;
			case '2':
				x |= S_IWUSR;
				break;
			case '1':
				x |= S_IXUSR;
				break;
		}
		if (i == 1)	buf.st_mode = x;
		if (i == 2)	buf.st_mode |= (x >> 3);
		if (i == 3)	buf.st_mode |= (x >> 6);
		i++;
	}

	chmod(argv[2], buf.st_mode);
	stat(argv[2], &buf);
	CheckPermission(argv[2]);
	
	return 0;
}

