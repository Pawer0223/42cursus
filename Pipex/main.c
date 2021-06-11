#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "pipex.h"

void	exec_gogo2()
{
	printf("gogo2\n");
	// 왜 앞에 명령어 또쓰냐? 그럼 execve 첫번째 인자는 의미 없는거아닌가 ㅡ..ㅡ
	char	*param[4] = {"tr", "\n", " ", 0};
	// 이거 env의 Path때문에 쓰는 갑다. 그래서 ls로 쓸 수 있는듯
	char	*envp[2] = {ENV_PATH, 0};
	execve("/usr/bin/tr", param, envp);
	printf("여기가 실행되면 하위 프로세스 호출에서 문제가 발생했다는 소린데 ;;;;;;;;\n");
}

void	exec_gogo()
{
	// 왜 앞에 명령어 또쓰냐? 그럼 execve 첫번째 인자는 의미 없는거아닌가 ㅡ..ㅡ
	char	*param[4] = {"grep", "zip", "./ls.txt", 0};
	// 이거 env의 Path때문에 쓰는 갑다. 그래서 ls로 쓸 수 있는듯
	char	*envp[2] = {ENV_PATH, 0};
	execve("/usr/bin/grep", param, envp);
	printf("여기가 실행되면 하위 프로세스 호출에서 문제가 발생했다는 소린데 ;;;;;;;;\n");
}

void	pipe_gogo()
{
	int		read_write[2];
	int		pid;
	int		status;

	// 파이프 호출하면 현재 프로세스에서 read, write할 fd를 알아서 지정해준다.
	pipe(read_write);
	// printf("read : %d, write : %d\n", read_write[0], read_write[1]);

	pid = fork();

	if (pid == -1)
	{
		printf("[ ### pid == -1 ### ]\n");
	}
	else if (pid == 0)
	{
		printf("[ ### pid == 0 ### ]\n");
		dup2(read_write[1], 1);
		close(read_write[0]);
		close(read_write[1]);
		exec_gogo();
	}
	else
	{
		waitpid(pid, &status, 0);
		// exec_gogo2();
		printf("======= here =======\n");
		char	*param[4] = {"tr", "\n", " ", 0};
		// 이거 env의 Path때문에 쓰는 갑다. 그래서 ls로 쓸 수 있는듯
		char	*envp[2] = {ENV_PATH, 0};
		execve("/usr/bin/tr", param, envp);
		printf("[ ### pid > 0 ### ]\n");
	}
}

void		test_main()
{
	// if (argc < 5)
	// 	printf("Please Call \"./pipex file1 cmd1 cmd2 file2\"\n"); // printf modify
	
	// 1. file1을 인자로
	pipe_gogo();
	// 그냥 바로돌려버리면, 결과가 바로 출력됨.
	// exec_gogo();
	// printf("여기가 실행되면 하위 프로세스 호출에서 문제가 발생했다는 소린데 ;;;;;;;;\n");
}
/*
	** ./pipex argv[1] = file1 argv[2] = cmd1 argv[3] = cmd2 argv[4] = file2

	1. file1을 입력으로 받아서 cmd1을 호출해준다.

	⇒ file1이 입력이라는건, 결국 문자열 처리를 의미하는가 ?

	2. 1의 결과로 cmd2를 다시한번 호출한다 ?

	⇒ 음.. 1의 결과는 결국 표준 출력.(모니터 출력) 아닐 수 있나 ?

	2-1) cmd1의 결과가 모니터 출력이 아니라면 ??

	무조건 출력이어야 하겠다. 왜냐하면 [ | 파이프 ]명령어가 필터기능을하니깐, 결국 선행 명령어의 결과를 참조해야 하니깐...

	3. 2의 결과를 파일로 저장.
*/

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