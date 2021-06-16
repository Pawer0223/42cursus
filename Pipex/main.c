#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "pipex.h"




void		test_main()
{
}


int		main(int argc, const char *argv[], char *envp[])
{
	if (argc < 5)
	{
		while (*envp)
		{
			char *env = *envp;
			if (ft_strlen(env) < 4)
				continue;
			if (env[0] == 'P' && env[1] == 'A' && env[2] == 'T' && env[3] == 'H')
				printf("%s\n", *envp);
			envp++;
		}
		test_main();
		// printf("Please Call \"./pipex file1 cmd1 cmd2 file2\"\n"); // printf modify
	}
	else
	{
		// main code

		int fd_1;

		if ((fd_1 = open(argv[1], O_RDONLY)) == -1)
			printf("Error\n File Open Error");
	}
	return (1);
}