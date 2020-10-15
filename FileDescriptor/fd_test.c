#include <fcntl.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h>

int main(void)
{
	int rfd, wfd, n;
	char buf[10];

	mode_t mode;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	wfd = open("unix.bak", O_CREAT | O_WRONLY | O_TRUNC, mode);
	rfd = open("unix.txt", O_RDONLY);

	if(rfd == -1) {
		perror("Open unix.txt");
		exit(1);
	}
	if (wfd == -1) {
		perror("Open unix.bak");
		exit(1);
	}

	printf("rfd is : [%d] , wfd is : [%d]\n",rfd, wfd);

	while((n = read(rfd, buf, 6)) > 0)
		if(write(wfd, buf, n) != n) perror("Write");
	if(n == -1) perror("Read");

	close(rfd);
	close(wfd);
}
