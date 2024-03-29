#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t threads[5];
int done[5];

void *thread_main(void *);

int main(void)
{
	int i;
	int rc;
	int status;
	
	printf("pid=%d\n", getpid());
	
	for (i = 0; i < 5; i++)
	{	
		done[i] = 0;
		pthread_create(&threads[i], NULL, &thread_main, (void *)i);
		printf("Create %d, %d\n", i, threads[i]);
	}

	for (i = 4; i >= 0; i--)
	{
		done[i] = 1;
		rc = pthread_join(threads[i], (void **)&status);
		if (rc == 0)
		{
			printf("Completed join with thread %d status= %d\n",i, status);
		}
		else
		{
			printf("ERROR; return code from pthread_join() is %d, thread %d\n", rc, i);
		 	return -1;
		}
	}

	return 0;
}

void	business(int arg, int i)
{
	// for (i=0; i < 1000000; i++)
	// {
	// 	result = result + (double)random();
	// }
	// printf("thread: %d, result = %e\n", (int)arg, result);
	usleep(1000000);
	printf("thread: %d, i = %d\n", arg, i);
}

void *thread_main(void *arg)
{
	int i;
	double result=0.0;

	printf("therad: %d, pid : %d\n", (int)arg, getpid());

	i = 0;
	while (!done[(int)arg])
	{
		business((int)arg, i++);
	}

	pthread_exit((void *) 0);
}