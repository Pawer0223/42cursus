#include "printf.h"

int		main(int argc, char *argv[])
{
//	argv = NULL;

	printf("argv[0]:%s\n",argv[0]);
	if (argc == 1)
		printf("please input formatString !\n");
	else
//		start("test1% 8427text2", 123, 45, 6789);
		start(argv[1], 123, 45, 6789);
}
