#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STDIN_PIPE 0x1
#define STDOUT_PIPE 0x2

void exec_command(char *command, int pipefd[2], int flags)
{
	// printf("command : [%s]\n", command);
	pid_t cpid = fork();

	if (cpid > 0) // parent
		return;
	else if (cpid < 0) // error
		perror("fork");
	else // child
	{
		char *const argv[] = {command, NULL};
		char *const envp[] = {NULL};

		printf("flags : %d, flags & STDIN_PIPE : %d, flags & STDOUT_PIPE : %d\n"
		, flags, (flags & STDIN_PIPE),(flags & STDOUT_PIPE)
		);

		if (flags & STDIN_PIPE) {
			printf("[%s], STDIN_PIPE ... fd => [%d]\n", command, pipefd[0]);
			if (dup2(pipefd[0], STDIN_FILENO) < 0)
				perror("dup2");
		}

		if (flags & STDOUT_PIPE) {
			printf("[%s], STDOUT_PIPE ... fd => [%d]\n", command, pipefd[1]);
			if (dup2(pipefd[1], STDOUT_FILENO) < 0)
				perror("dup2");
		}
		close(pipefd[0]);
		close(pipefd[1]);
		execve(command, argv, envp);
		perror("execv");
	}
}
// void exec_command(char *command, int pipefd[2], int flags)
// {
// 	pid_t cpid = fork();

// 	/*
// 		** fork 이후에 처리되는 코드들 ..
// 	*/
	
// 	// 부모 프로세스 일 때
// 	if (cpid > 0)
// 		return;
// 	else if (cpid < 0)
// 		perror("fork");

// 	// 자식 프로세스 일 때
// 	char *const argv[] = {command, NULL};
// 	char *const envp[] = {NULL};

// 	// 표준, 입출력에 따른 파일 디스크립터 복사 작업.
// 	if (flags & STDIN_PIPE)
// 		if (dup2(pipefd[0], STDIN_FILENO) < 0)
// 			perror("dup2");

// 	if (flags & STDOUT_PIPE)
// 		if (dup2(pipefd[1], STDOUT_FILENO) < 0)
// 			perror("dup2");

// 	// 프로세스 내에서만 쓰기 때문에, 닫아주고
// 	// 의문, 호출하기전에 닫으면.. 결과 받기도 전에 닫히는거 아님 ?
//     // 현재 파일이 표준 입력 or 출력으로 변환되 었음.
// 	close(pipefd[0]);
// 	close(pipefd[1]);

// 	// 실제로 호출하는 코드
// 	execve(command, argv, envp);

// 	// 에러일 때만 출력
// 	perror("execv");
// }

void three_inst()
{
	int pipefd1[2], pipefd2[2];

	pipe(pipefd1);
	pipe(pipefd2);

	printf("fds[0] : %d, fds[1] : %d, fds_2[0] : %d, fds_2[1] : %d\n", pipefd1[0], pipefd1[1], pipefd2[0], pipefd2[1]);

	exec_command("/bin/ls", pipefd1, STDOUT_PIPE);
	close(pipefd1[1]);
	exec_command("/usr/bin/wc", pipefd2, STDIN_PIPE);
	close(pipefd2[0]);

	int temp_pipefd[] = {pipefd1[0], pipefd2[1]};
	exec_command("/usr/bin/wc", temp_pipefd, STDIN_PIPE | STDOUT_PIPE);
	printf("STDIN_PIPE | STDOUT_PIPE => [%d]\n", (STDIN_PIPE | STDOUT_PIPE));

	close(pipefd1[0]);
	close(pipefd2[1]);

	int wstatus;
	while (wait(&wstatus) > 0);
}

void two_inst()
{
	int pipefd1[2];
	pipe(pipefd1);

	exec_command("/bin/ls", pipefd1, STDOUT_PIPE);
	close(pipefd1[1]);
	exec_command("/usr/bin/wc", pipefd1, STDIN_PIPE);
	close(pipefd1[0]);

	// 부모 프로세스에서 기다리고 있는 상태.
	int wstatus;
	while (wait(&wstatus) > 0);
}

int main()
{
	// two_inst();
	three_inst();
	return 0;
}