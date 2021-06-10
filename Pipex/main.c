#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
	** ./pipex argv[1] = file1 argv[2] = cmd1 argv[3] = cmd2 argv[4] = file2
*/
void		test_main()
{
	// if (argc < 5)
	// 	printf("Please Call \"./pipex file1 cmd1 cmd2 file2\"\n"); // printf modify
	int	fd_1;

	if ((fd_1 = open("./ls.txt", O_RDONLY)) == -1)
		printf("Error\n File Open Error");
	// 1. file1을 인자로
	char	*param[3] = {"ls", "-altr", 0};
	char	*envp[3] = {"why", "use?", 0};
	execve("/bin/ls", param, envp);
	free(param);
	printf("여기가 안실행된다고? \n");

	// 2. cmd1을 수행

	// 2 -> 3 넘어갈때, 수행결과가 실행되면 안됨. 이어서 3이 처리되도록.

	// 3. 2의 결과를 인자로

	// 4. cmd2를 수행

	// 5. 4의 결과를 file2로 저장.	
	close(fd_1);
}

int		main(int argc, const char *argv[])
{
	if (argc < 5)
	{
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