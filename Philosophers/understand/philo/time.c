/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:35:37 by taesan            #+#    #+#             */
/*   Updated: 2021/07/18 02:13:40 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_curr_time(void)
{
	struct timeval	tv;
	long long		curr;

	gettimeofday(&tv, NULL);
	curr = (tv.tv_sec * MS) + (tv.tv_usec / MS);
	return (curr);
}
