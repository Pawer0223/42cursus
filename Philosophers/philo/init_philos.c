/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:09:34 by taesan            #+#    #+#             */
/*   Updated: 2021/07/17 20:44:25 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_fork(t_philo **philos, pthread_mutex_t **f, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		philos[i]->left = f[i];
		philos[i]->right = f[(i + 1) % cnt];
		i++;
	}
}

void	set_philos(t_program_data data, int idx)
{
	t_param common;
	t_philo	**philos;

	common = data.common;
	philos = data.philos;
	philos[idx]->seq = idx + 1;
	philos[idx]->common->num_of_philo = common.num_of_philo;
	philos[idx]->common->time_to_die = common.time_to_die;
	philos[idx]->common->time_to_eat = common.time_to_eat;
	philos[idx]->common->time_to_sleep = common.time_to_sleep;
	philos[idx]->common->time_each_must_eat = common.time_each_must_eat;
	pthread_mutex_init(data.forks[idx], NULL);
}

void	init_philos(t_program_data data, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
		set_philos(data, i++);
	set_fork(data.philos, data.forks, cnt);
}
