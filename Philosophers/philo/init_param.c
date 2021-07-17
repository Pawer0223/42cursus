/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:09:34 by taesan            #+#    #+#             */
/*   Updated: 2021/07/17 03:18:04 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_param(t_param *common, char *argv[])
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
	return (1);
}