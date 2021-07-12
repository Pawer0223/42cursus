#include "understand.h"

int	done[3];

void	*thread_main_detach(void *param)
{
	int	i;
	int	seq;

	seq = (int)param;
	i = 0;
	while (!done[seq])
	{
		printf("Thread : [%d] - i : %d\n", seq, i);
		i++;
	}
	return (void *)(long)seq; // (long)하니까 warning이 사라지네 ?
}

int	understand_detach(int n)
{
	pthread_t	**thread_arr;
	int			i;
	int			r;
	int			j;
	long		return_v;

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
		pthread_create(thread_arr[i], NULL, thread_main_detach, (void *)(long)i);
		i++;
	}

	printf("--------- middle ---------\n");
	j = n - 1; 
	while (j >= 0)
	{
		done[j] = 1;
		r = pthread_detach(*thread_arr[j]);
		// r = pthread_join(*thread_arr[j], (void **)&return_v);
		if (r == 0)
			printf("Completed join with thread %d status= %ld\n", j, return_v);
		else
		{
			printf("pthread_join error : [%d]\n", j);
			return (0);
		}
		j--;
	}
	return (1);
}