#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void    *thread_main(void *param)
{
	int in_value =  *(int *)param;
	if (in_value == 0) {
		sleep(1);
	}
	int out_value = *(int *)param;
	printf("thread in : [%d], out : [%d]\n", in_value, out_value);
	pthread_exit(0);
}

int     main()
{
	int			i;
	int			result;
	pthread_t	threads[3];

	printf("i가 0, 1, 2일때 주소 값을 던진다.\n");
	printf("but i == 0일 때, 1초동안 쓰레드를 멈추면 이 후 코드(i++)가 먼저 실행됨으로 0초과의 값이 나와야 한다.\n");
	printf("but thread_main보다도 i++가 먼저 돌수도 있다. in값이 1, 2, 1인 경우도 존재한다.\n");
	printf("즉, thread돌기전에 i++가 먼저타는 경우도 발생할 수 있음.\n");
	
	i = 0;
	while (i < 3) {
		pthread_create(&threads[i], NULL, thread_main, &i);
		i++;
	}

	/* 이거 안하면, 메인이 먼저끝나버림. */
	i = 0;
	while (i < 3) {
		pthread_join(threads[i++], (void **)&result);
	}
	return (1);
}