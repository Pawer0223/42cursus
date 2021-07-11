#include "understand.h"

int	done[3];

void	*thread_main_fail(void *param)
{
	int	i;
	int	seq;

	seq = *(int *)param; // 무한루프 빠질 때
	// seq = (int)param;
	i = 0;
	printf("=== seq : %d ===\n", seq);
	while (!done[seq])
	{
		printf("Thread %d\n", seq);
		//printf("Thread : [%d] - i : %d\n", seq, i);
		i++;
		//usleep(SECOND);
	}
	return (void *)(long)seq; // (long)하니까 warning이 사라지네 ?
}

/*
	**	create하는데 시간이 걸린다. 돌려놓고 하위코드 수행. (비동기 처리 느낌이네..)
	** 그래서 참고한 예제에서는 join을 마지막에 생성한 쓰레드부터 가나보다... 근데 그래도 순서가 보장되지 않는다... 
	** 그래서 usleep으로 지연을 조금 시키니깐 의도한대로 순서는 흘러 감.
*/
int	understand_thread_fail(int n)
{
	pthread_t	**thread_arr;
	int			i;
	int			return_v;

	thread_arr = (pthread_t **)malloc(sizeof(pthread_t *) * n);
	if (!thread_arr)
		return (0);
	i = 0;
	while (i < n)
	{
		thread_arr[i] = (pthread_t *)malloc(sizeof(pthread_t));
		done[i] = 0;
		if (!thread_arr[i])
			return (0);
		pthread_create(thread_arr[i], NULL, thread_main_fail, &i); // 무한루프 빠짐
		// pthread_create(thread_arr[i], NULL, thread_main, (void *)i);
		// usleep(SECOND);
		i++;
	}

	// printf("--------- middle ---------\n");

	i = n - 1;
	while (i >= 0)
	{
		done[i] = 1;
		// printf("### done[%d] set 1 ###\n", i);
		printf("join [%d]\n", i);
		int r = pthread_join(*thread_arr[i], (void **)&return_v);
		printf("after join : [%d]\n", i);
		if (r == 0)
		{
			printf("Completed join with thread %d status= %d\n", i, return_v);
		//	printf("[%d] finish\n", return_v);
		}
		else
		{
			printf("pthread_join error : [%d]\n", i);
			return (0);
		}
		i--;
	}
	printf("### understand_thread finish ###\n");
	return (1);
}