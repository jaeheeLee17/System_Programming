#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	struct stat buf;
	int kind;

	stat(argv[1], &buf);

	printf("File Name : %s\n", argv[1]);
	printf("Inode : %d\n", (int)buf.st_ino);
	kind = buf.st_mode & S_IFMT;
	switch (kind) {
		case S_IFIFO:
			printf("File Type : FIFO File\n");
			break;
		case S_IFCHR:
			printf("File Type : Character Device Special File\n");
			break;
		case S_IFDIR:
			printf("File Type : Directory\n");
			break;
		case S_IFBLK:
			printf("File Type : Block Device Special File\n");
			break;
		case S_IFREG:
			printf("File Type : Regular File\n");
			break;
		case S_IFLNK:
			printf("File Type : Symbolic Link File\n");
			break;
		case S_IFSOCK:
			printf("File Type : Socket File\n");
			break;
	}
	printf("Access Permission : ");
	if ((buf.st_mode & S_IRUSR) != 0)	printf("r");
	else	printf("-");
	if ((buf.st_mode & S_IWUSR) != 0)	printf("w");
	else	printf("-");
	if ((buf.st_mode & S_IXUSR) != 0)	printf("x");
	else	printf("-");
	if ((buf.st_mode & S_IRGRP) != 0)	printf("r");
	else	printf("-");
	if ((buf.st_mode & S_IWGRP) != 0)	printf("w");
	else	printf("-");
	if ((buf.st_mode & S_IXGRP) != 0)	printf("x");
	else	printf("-");
	if ((buf.st_mode & S_IROTH) != 0)	printf("r");
	else	printf("-");
	if ((buf.st_mode & S_IWOTH) != 0)	printf("w");
	else	printf("-");
	if ((buf.st_mode & S_IXOTH) != 0)	printf("x\n");
	else	printf("-\n");
	printf("UID : %d\n", (int)buf.st_uid);
	printf("File Change Time : %d\n", (int)buf.st_mtime);
	
	return 0;
}
