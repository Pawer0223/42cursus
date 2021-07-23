/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:09:34 by taesan            #+#    #+#             */
/*   Updated: 2021/07/23 02:49:07 by taesan           ###   ########.fr       */
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

sem_t	*create_sem(char *name, int value)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	return (sem);
}

void	set_status(t_philo *philo, int seq)
{
	int		size;
	int		n;
	char	name[50];

	memset(name, 0, 50);
	size = 0;
	n = seq;
	while (n)
	{
		n /= 10;
		size++;
	}
	name[size--] = 0;
	n = seq;
	while (size >= 0 && n)
	{
		name[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	philo->status = create_sem(SEM_FORKS, 1);
}

void	init_philos(t_program_data *data, t_common *common, int cnt)
{
	int	i;

	common->start = get_curr_time();
	common->finish_sem = create_sem(SEM_FINISH, 0);
	common->must_eat_sem = create_sem(SEM_MUST_EAT, 0);
	common->forks = create_sem(SEM_FORKS, common->num_of_philo);
	i = 0;
	while (i < cnt)
	{
		data->philos[i].last_time = data->common.start;
		data->philos[i].seq = i + 1;
		data->philos[i].common = &data->common;
		data->philos[i].eat_cnt = 0;
		set_status(&data->philos[i], i + 1);
		i++;
	}
}

int	init(t_program_data *data, char *argv[])
{
	t_philo	*philos;

	if (!init_param(&data->common, argv))
		return (error_occur(PARAM_ERROR));
	philos = (t_philo *)malloc(sizeof(t_philo) * data->common.num_of_philo);
	if (!philos)
		return (error_occur(MALLOC_ERROR));
	data->philos = philos;
	init_philos(data, &data->common, data->common.num_of_philo);
	return (1);
}
