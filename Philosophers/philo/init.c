/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:09:34 by taesan            #+#    #+#             */
/*   Updated: 2021/07/19 16:05:13 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_param(t_common *common, char *argv[])
{
	int	i;

	i = 1;
	common->num_of_philo = ft_atoi(argv[i++]);
	if (!common->num_of_philo)
		return (0);
	common->time_to_die = ft_atoi(argv[i++]);
	if (!common->time_to_die)
		return (0);
	common->time_to_eat = ft_atoi(argv[i++]);
	if (!common->time_to_eat)
		return (0);
	common->time_to_sleep = ft_atoi(argv[i++]);
	if (!common->time_to_sleep)
		return (0);
	if (argv[i])
	{
		common->time_each_must_eat = ft_atoi(argv[i]);
		if (!common->time_each_must_eat)
			return (0);
	}
	else
		common->time_each_must_eat = -1;
	common->start = get_curr_time();
	return (1);
}

int	malloc_data(t_program_data *data, int cnt)
{
	data->philos = (t_philo *)malloc(sizeof(t_philo) * cnt);
	if (!data->philos)
		return (0);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * cnt);
	if (!data->forks)
	{
		free(data->philos);
		return (0);
	}
	data->threads = (pthread_t *)malloc(sizeof(pthread_t) * cnt);
	if (!data->threads)
	{
		free(data->philos);
		free(data->forks);
		return (0);
	}
	return (1);
}

int	init_philos(t_program_data *data, int cnt)
{
	int	i;

	if (!malloc_data(data, cnt))
		return (0);
	i = 0;
	while (i < cnt)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		if (i < cnt - 1)
			pthread_mutex_init(&data->forks[i + 1], NULL);
		data->philos[i].last_time = data->common.start;
		data->philos[i].seq = i + 1;
		data->philos[i].common = data->common;
		data->philos[i].left = &data->forks[i];
		data->philos[i].right = &data->forks[(i + 1) % cnt];
		i++;
	}
	return (1);
}

int	init(t_program_data *data, char *argv[])
{
	if (!init_param(&data->common, argv))
		return (error_occur(PARAM_ERROR));
	if (!init_philos(data, data->common.num_of_philo))
		return (error_occur(MALLOC_ERROR));
	return (1);
}
