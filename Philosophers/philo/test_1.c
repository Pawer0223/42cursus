#include "philo.h"

int	done[3];

void	understand_usleep()
{
	int i = 0;

	unsigned int sec;

	while (i < 10) {
		useconds_t sec = SECOND + 10000;
		int result = usleep(sec);
		printf("i : %d, result : %d\n", i, result);
		i++;
	}
}

void	*thread_main(void *param)
{
	int	i;
	int	seq;

	seq = *((int *)param);
	i = 0;
	while (!done[seq])
	{
		printf("Thread : [%d] - i : %d\n", seq, i);
		i++;
		usleep(SECOND);
	}
	return (void *)seq; // warning발생 함.
}

int	understand_thread(int n)
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
		pthread_create(thread_arr[i], NULL, thread_main, (void *)&i);
		i++;
	}

	i = 0;
	while (i < n)
	{
		done[i] = 1;
		if (pthread_join(*thread_arr[i], (void **)&return_v) == 0)
			printf("[%d] finish\n", return_v);
		else
		{
			printf("pthread_join error : [%d]\n", i);
			return (0);
		}
		printf("[ %d ]\n", i);
		i++;
	}

	printf("### understand_threadd finish ###\n");
	return (1);
}

void	test_1() {

	int param_1 = 2; // number_of_philosophers
	int param_2 = 5; // time_to_die
	int param_3 = 2; // time_to_eat
	int param_4 = 2; // time_to_sleep
	int param_5 = 10; //[number_of_times_each_philosopher_must_eat]

	// understand_usleep();

	int n = 3;
	understand_thread(n);
}