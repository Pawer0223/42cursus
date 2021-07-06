#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STDIN_PIPE 0x1
#define STDOUT_PIPE 0x2

void exec_command_print(char *command, int pipefd[2], int flags)
{
	pid_t cpid = fork();

	if (cpid > 0) // parent
	{
		printf("parent processing .... \n");
		return;
	}
	else if (cpid < 0) // error
		perror("fork");
	else // child
	{
		printf("child processing .... \n");
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
		printf("before close\n");
		close(pipefd[0]);
		close(pipefd[1]);
		printf("before execve\n");
		execve(command, argv, envp);
		perror("execv");
	}	
}


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

		if (flags & STDIN_PIPE) {
			if (dup2(pipefd[0], STDIN_FILENO) < 0)
				perror("dup2");
		}

		if (flags & STDOUT_PIPE) {
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

	// printf("fds[0] : %d, fds[1] : %d, fds_2[0] : %d, fds_2[1] : %d\n", pipefd1[0], pipefd1[1], pipefd2[0], pipefd2[1]);

	char *ls = "/bin/ls";
	char *wc = "/usr/bin/wc";
	char *echo = "/bin/echo";


	// pipe1에 데이터 저장
	exec_command(ls, pipefd1, STDOUT_PIPE);
	close(pipefd1[1]);
	/*
		표준 입력을 pipefd2[0]의 fd정보로써, 대기하는 wc명령이 수행된다.
		따라서 close(pipefd2[1]);이후에 명령어가 수행 됨. (파이프의 출력이 종료되었음을 알리기 때문에.)
	*/ 
	exec_command(echo, pipefd2, STDIN_PIPE);
	close(pipefd2[0]);
	/*
		두개의 파이프를 연결한 새로운 파이프가 된다.
	*/
	int temp_pipefd[] = {pipefd1[0], pipefd2[1]};
	/* 
		해당 명령어는, pipefd1[0]을 표준 입력으로써, pipefd2로 출력 하게된다.
		
		즉, 세번째 명령어가 pipefd1[0]에 저장된 데이터로 명령어를 수행하는건가 ??
		그 결과가 pipefd2에 저장이 되면은,

		이후에 close(pipefd2[1]);됐을 때는 두번째 명령어가 수행되는겨 ?

		결국, 마지막에 표준 출력은 2번째 명령어라는 소린건가 ?
	*/ 
	exec_command(wc, temp_pipefd, STDIN_PIPE | STDOUT_PIPE);
	close(pipefd1[0]);
	
	close(pipefd2[1]); // 이게 호출 될 때 처리되는데.. 동시에 처리된다?

	int wstatus;
	while (wait(&wstatus) > 0);
}

/*
 첫번째 명령의 결과를 가지고
 두번째 명령어 수행하기.
*/
void two_inst()
{
	int pipefd1[2];
	pipe(pipefd1);

	// 첫번째 명령어를 파이프에 저장하고
	exec_command("/bin/ls", pipefd1, STDOUT_PIPE);
	close(pipefd1[1]);

	// 해당 파이프를 표준입력으로 데이터를 받아, 두번째 명령어 수행하기.
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