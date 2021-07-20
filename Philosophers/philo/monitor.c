/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 04:18:19 by taesan            #+#    #+#             */
/*   Updated: 2021/07/20 20:37:12 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_philo *philo;
	long long	wait_time;
	long long	timestamp;

	philo = (t_philo *)arg;
	while (!philo->common->is_finish)
	{
		// 여기서 결국 공유데이터를 참조하기 때문에, 다른 쓰레드에서 변경될 가능성이 존재한다.
		// 따라서 해당 철학자의 정보를 참조할 때는, 락을 걸어준다.
		pthread_mutex_lock(&philo->common->finish_mutex);
		pthread_mutex_lock(&philo->philo_status);
		wait_time = get_curr_time() - philo->last_time;
		pthread_mutex_unlock(&philo->philo_status);
		if (wait_time >= philo->common->time_to_die && !philo->common->is_finish)
		{
			philo->common->is_finish = 1;
			timestamp = get_curr_time() - philo->common->start;
			printf("%lld\t%d\t%s\n", timestamp, philo->seq, PRINT_DIE);
		}
		pthread_mutex_unlock(&philo->common->finish_mutex);
	}
	return (0);
}