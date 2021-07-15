#include "understand.h"

#define SIZE 5
#define ONE_SEC 1000000

char	*meal[3] = {"breakfast", "lunch", "dinner"};

typedef struct	s_phil
{
	int				seq;
	int				eat;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
}				t_phil;

long long	get_working_time(long long start)
{
	struct timeval	end;
	long long		e;
	gettimeofday(&end, NULL);
	e = end.tv_sec * MS + end.tv_usec / MS;
	return e - start;
}

void	*thread_main_mutex(void	*arg)
{
	t_phil *philo;
	struct timeval start;

	philo = (t_phil *)(arg);

	// 밥을 3번먹을 동안 계속돈다.
	// 밥을 한번 먹고난다음에는 1초동안 쉰다.
	gettimeofday(&start, NULL);
	long long s = start.tv_sec * MS + start.tv_usec / MS;

	while (philo->eat < 3)
	{
		// 포크가 살아있을 때 잡기.
		pthread_mutex_lock(philo->left);
		pthread_mutex_lock(philo->right);
		long long working = get_working_time(s);
		printf("%lldms [%d] philosopher eat [%s]!\n", working, philo->seq, meal[philo->eat]);
		// 밥을 먹고.
		philo->eat++;
		// 1초동안 잔다.
		usleep(ONE_SEC / 2);
		// 포크 놓아주기.
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
	return (0);
}

/*
	자기자신(왼쪽) + 오른쪽의 포크를 사용가능. 

	1 -> 2 , 2 -> 3, . . . N -> 1

	5개의 철학자가 3번의 식사를 해야한다.
		- 최대 2명의 철학자가 함께 밥을먹을 수 있다.
		- i번째 철학자는 i + 1번째 철학자와 동시에 같은 seq의 식사를 병행할 수 없다.(i가 끝나고, 바로 i + 1이 수행될 순 있음)
*/
void	undestand_mutex()
{
	pthread_t		threads[SIZE];
	pthread_mutex_t	forks[SIZE];
	t_phil			philos[SIZE];
	int				i;

	// 포크를 만들기
	i = 0;
	while (i < SIZE)
		pthread_mutex_init(&forks[i++], NULL);
	i = 0;
	// 각자 포크 쥐어주기
	while (i < SIZE)
	{
		philos[i].eat = 0;
		philos[i].seq = i + 1;
		philos[i].left = &forks[i];
		philos[i].right = &forks[((i + 1) % SIZE)];
		i++;
	}
	i = 0;
	// 각 철학자를 앉혀놓기
	while (i < SIZE)
	{
		pthread_create(&threads[i], NULL, thread_main_mutex, &philos[i]);
		i++;
	}
	for (int i = 0; i < SIZE; i++) {
		pthread_join(threads[i], NULL);
	}
}