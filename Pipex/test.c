#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STDIN_PIPE 0x1
#define STDOUT_PIPE 0x2

void exec_command(char *command, int pipefd[2], int flags)
{
	pid_t cpid = fork();

	/*
		** fork 이후에 처리되는 코드들 ..
	*/
	
	// 부모 프로세스 일 때
	if (cpid > 0)
		return;
	else if (cpid < 0)
		perror("fork");

	// 자식 프로세스 일 때
	char *const argv[] = {command, NULL};
	char *const envp[] = {NULL};

	// 표준, 입출력에 따른 파일 디스크립터 복사 작업.
	if (flags & STDIN_PIPE)
		if (dup2(pipefd[0], STDIN_FILENO) < 0)
			perror("dup2");

	if (flags & STDOUT_PIPE)
		if (dup2(pipefd[1], STDOUT_FILENO) < 0)
			perror("dup2");

	// 프로세스 내에서만 쓰기 때문에, 닫아주고
	// 의문, 호출하기전에 닫으면.. 결과 받기도 전에 닫히는거 아님 ?
	close(pipefd[0]);
	close(pipefd[1]);

	// 실제로 호출하는 코드
	execve(command, argv, envp);

	// 에러일 때만 출력
	perror("execv");
}

void three_inst()
{
	int pipefd1[2], pipefd2[2];
	// fd1, fd2
	pipe(pipefd1);
	// fd3, fd4
	pipe(pipefd2);

	exec_command("/bin/ls", pipefd1, STDOUT_PIPE);
	close(pipefd1[1]);
	exec_command("/usr/bin/wc", pipefd2, STDIN_PIPE);
	close(pipefd2[0]);

	int temp_pipefd[] = {pipefd1[0], pipefd2[1]};
	exec_command("/usr/bin/wc", temp_pipefd, STDIN_PIPE | STDOUT_PIPE);

	close(pipefd1[0]);
	close(pipefd2[1]);

	int wstatus;
	while (wait(&wstatus) > 0);
}

void two_inst()
{
	int pipefd1[2];
	// 파이프 생성, 표준 입력, 출력에 대한 fd가 지정 됨.
	pipe(pipefd1);

	/*
		** 따로 입력이 필요없는 프로그램. 파라미터로 호출 가능함. 파라미터 없어도 호출 가능 함.
		** pipe를 보낸다.
		** 출력을 stdout(1)으로 보냄
	*/
	exec_command("/bin/ls", pipefd1, STDOUT_PIPE);
	/*
		** stdout안쓰니깐 닫아준다 ?
		** 맞음 ?
	*/
	close(pipefd1[1]);
	/*
		** 입력을 대기하는 프로그램
		** 어떻게 위의 결과를 입력으로 받을 수 있는거지 ?
	*/
	exec_command("/usr/bin/wc", pipefd1, STDIN_PIPE);
	/*
		** 다 끝내고 입력도 다썼으니깐 닫아주기 ?
	*/
	close(pipefd1[0]);

	// 이것도 모르겠고..
	int wstatus;
	while (wait(&wstatus) > 0);
}

int main()
{
	two_inst();
	// three_inst();
	return 0;
}