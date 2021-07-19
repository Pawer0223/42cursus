#include "philo.h"

void	set_timestamp(t_timestamp *ts, int act)
{
	long long time;

	time = get_curr_time() - ts->start;
	if (act == ACT_EAT)
		ts->eat = time;
	else if (act == ACT_TAKE)
		ts->take = time;
	else if (act == ACT_SLEEP)
		ts->sleep = time;
	else if (act == ACT_DIE)
		ts->die = time;
	else if (act == ACT_THINK)
		ts->think = time;
}

void	print_log(t_timestamp *ts, int seq)
{
	// 잡기
	printf("%lldms %d %s\n", ts->take, seq, PRINT_TAKE);
	// 먹기
	printf("%lldms %d %s\n", ts->eat, seq, PRINT_EAT);
	// 자기
	printf("%lldms %d %s\n", ts->sleep, seq, PRINT_SLEEP);
	// 생각하기
	printf("%lldms %d %s\n", ts->think, seq, PRINT_THINK);
}

void	*thread_main(void *arg)
{
	t_philo *philo;
	long long curr;
	t_timestamp ts;

	while (1)
	{
		philo = (t_philo *)arg;
		ts.start = philo->common.start;
		// 포크를 잡았을 때, 기다린 시간을 체크해야 한다.
		pthread_mutex_lock(philo->left);
		pthread_mutex_lock(philo->right);
		// 이 curr는 조건에 따라 사용이 구분된다.
		// 현재시간을 기준으로 쓰레드가 종료조건이라면, 죽을 때 출력.
		// 종료조건이 아니라면, 포크를 줏을때 출력.
		curr = get_curr_time();
		ts.die = curr - philo->common.start;
		ts.take = ts.die;
		// 죽었으면 종료.
		if ((curr - philo->last_time) > philo->common.time_to_die)
			break;
		
		// 안죽었으면 ?

		// 철학자의 마지막 시간을 식사 시작시간으로 변경해준다.
		// philo->last_time = curr;

		// 먹고
		set_timestamp(&ts, ACT_EAT);
		usleep(philo->common.time_to_eat * MS);

		// 포크 놓고, 잠깐 쉬어주기(스케줄링을 위해 하나의 쓰레드가 계속 점유하는 상황을 회피하기위해 잠깐 쉬어줌.)
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		usleep(50);		
		
		// 자고
		set_timestamp(&ts, ACT_SLEEP);
		usleep(philo->common.time_to_sleep * MS);
		
		// 생각 중인 상태로 변경한다.
		set_timestamp(&ts, ACT_THINK);

		/*
		 	상태를 출력한다.
			다른 쓰레드가 출력되는 동안에, 출력되어선 안된다.


		*/
		// lock 
		print_log(&ts, philo->seq);
		// unlock
	}

	printf("%lldms %d %s\n", (curr - philo->common.start), philo->seq, PRINT_DIE);
	// 반복문을 빠져나왔을 때, 철학자가 죽었을 때 쥐고있던 포크를 놓아준다.
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (0);
}