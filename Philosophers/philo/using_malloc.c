/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:54:47 by taesan            #+#    #+#             */
/*   Updated: 2021/07/17 20:59:01 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	program_data_per_malloc(t_program_data	*data, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		data->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!data->philos[i])
			return (0);
		ft_bzero(data->philos[i], sizeof(t_philo));
		data->philos[i]->common = (t_param *)malloc(sizeof(t_param) * cnt);
		if (!data->philos[i]->common)
			return (0);
		data->forks[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!data->forks[i])
			return (0);
		data->threads[i] = (pthread_t *)malloc(sizeof(pthread_t));
		if (!data->threads[i])
			return (0);
		i++;
	}
	return (1);
}

int	program_data_malloc(t_program_data	*data, int cnt)
{
	int	i;

	data->philos = (t_philo **)malloc(sizeof(t_philo *) * cnt);
	if (!data->philos)
		return (0);
	data->forks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * cnt);
	if (!data->forks)
		return (0);
	data->threads = (pthread_t **)malloc(sizeof(pthread_t *) * cnt);
	if (!data->threads)
		return (0);
	i = 0;
	while (i < cnt)
	{
		data->philos[i] = 0;
		data->forks[i] = 0;
		data->threads[i] = 0;
		i++;
	}
	if (!program_data_per_malloc(data, cnt))
		return (error_occur(MALLOC_ERROR));
	return (1);
}