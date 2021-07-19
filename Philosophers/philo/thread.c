#include "philo.h"

void	*thread_main(void *arg)
{
	t_philo *philo;
	long long curr;
	int	is_die;

	is_die = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		// 포크를 잡았을 때, 기다린 시간을 체크해야 한다.
		pthread_mutex_lock(philo->left);
		pthread_mutex_lock(philo->right);
		
		if (philo->common.is_finish)
			break ;
		// 이 curr는 조건에 따라 사용이 구분된다. 현재시간을 기준으로 쓰레드가 종료조건이라면, 죽을 때 출력.
		// 종료조건이 아니라면, 포크를 줏을때 출력.
		curr = get_curr_time();		
		// 죽었으면 종료.
		if ((curr - philo->last_time) > philo->common.time_to_die)
		{
			is_die = 1;
			pthread_mutex_unlock(philo->left);
			pthread_mutex_unlock(philo->right);
			break;
		}
		printf("%lldms %d %s\n", (curr - philo->common.start), philo->seq, PRINT_TAKE);
		philo->last_time = curr;
		printf("%lldms %d %s\n", (get_curr_time() -  philo->common.start), philo->seq, PRINT_EAT);
		// 안죽었으면 먹기
		usleep(philo->common.time_to_eat * MS);
		// 포크 놓기
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);

		// 겹치는거 방지.
		usleep(50);
		
		printf("%lldms %d %s\n", (get_curr_time() -  philo->common.start), philo->seq, PRINT_SLEEP);
		// 잠자기
		usleep(philo->common.time_to_sleep * MS);
		printf("%lldms %d %s\n", (get_curr_time() -  philo->common.start), philo->seq, PRINT_THINK);
	}
	if (is_die)
	{
		printf("%lldms %d %s\n", (curr - philo->common.start), philo->seq, PRINT_DIE);
		philo->common.is_finish = 1;
		// 반복문을 빠져나왔을 때, 철학자가 죽었을 때 쥐고있던 포크를 놓아준다.
	}
	return (0);
} 


