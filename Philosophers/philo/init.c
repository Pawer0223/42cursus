/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:09:34 by taesan            #+#    #+#             */
/*   Updated: 2021/07/20 18:23:02 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_param(t_common *common, char *argv[])
{
	int	i;

	i = 1;
	common->num_of_philo = ft_atoi(argv[i++]);
	if (common->num_of_philo < 0)
		return (0);
	common->time_to_die = ft_atoi(argv[i++]);
	if (common->time_to_die < 0)
		return (0);
	common->time_to_eat = ft_atoi(argv[i++]);
	if (common->time_to_eat < 0)
		return (0);
	common->time_to_sleep = ft_atoi(argv[i++]);
	if (common->time_to_sleep < 0)
		return (0);
	if (argv[i])
	{
		common->time_each_must_eat = ft_atoi(argv[i]);
		if (common->time_each_must_eat < 0)
			return (0);
	}
	else
		common->time_each_must_eat = -1;
	return (1);
}

void	init_common(t_common *common)
{
	common->start = get_curr_time();
	common->is_finish = 0;
	pthread_mutex_init(&common->finish_mutex, NULL);
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
		data->philos[i].left = &data->forks[i];
		data->philos[i].right = &data->forks[(i + 1) % cnt];
		data->philos[i].common = &data->common;
		pthread_mutex_init(&data->philos[i].last_time_mutex, NULL);
		i++;
	}
	return (1);
}

int	init(t_program_data *data, char *argv[])
{
	if (!init_param(&data->common, argv))
		return (error_occur(PARAM_ERROR));
	init_common(&data->common);
	if (!init_philos(data, data->common.num_of_philo))
		return (error_occur(MALLOC_ERROR));
	return (1);
}
