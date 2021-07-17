/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:09:34 by taesan            #+#    #+#             */
/*   Updated: 2021/07/17 19:34:37 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	call_free(t_philo **p, int p_e, pthread_mutex_t	**f, int f_e)
{
	double_ptr_free((void **)p, p_e);
	double_ptr_free((void **)f, f_e);
	return (0);
}

void	set_fork(t_philo **philos, pthread_mutex_t **f, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
		pthread_mutex_init(f[i++], NULL);
	i = 0;
	while (i < cnt)
	{
		philos[i]->left = f[i];
		philos[i]->right = f[(i + 1) % cnt];
		i++;
	}
}

int	malloc_datas(t_philo **philos, pthread_mutex_t **f, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philos[i])
			return (call_free(philos, i - 1, f, 0));
		f[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!f[i])
			return (call_free(philos, cnt, f, i - 1));
		i++;
	}
	return (1);
}

int	set_philos(t_philo **philos, t_param common, int idx)
{
	int	i;
	int	cnt;

	cnt = common.num_of_philo;
	philos[idx]->common = (t_param *)malloc(sizeof(t_param) * cnt);
	if (!philos[idx]->common)
	{
		i = 0;
		while (i < idx)
			free(philos[i++]->common);
		return (0);
	}
	philos[idx]->common->num_of_philo = common.num_of_philo;
	philos[idx]->common->time_to_die = common.time_to_die;
	philos[idx]->common->time_to_eat = common.time_to_eat;
	philos[idx]->common->time_to_sleep = common.time_to_sleep;
	philos[idx]->common->time_each_must_eat = common.time_each_must_eat;
	philos[idx]->seq = idx + 1;
	return (1);	
}

int	init_philos(t_philo **philos, pthread_mutex_t **f, t_param common)
{
	int	i;
	int	j;
	int	cnt;

	cnt = common.num_of_philo;
	if (!malloc_datas(philos, f, cnt))
		return (0);
	i = 0;
	while (i < cnt)
	{
		ft_bzero(philos[i], sizeof(t_philo));
		if (!set_philos(philos, common, i))
			return (call_free(philos, cnt, f, cnt));		
		i++;
	}
	set_fork(philos, f, cnt);
	return (1);
}
