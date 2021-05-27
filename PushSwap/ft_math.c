/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:29:11 by taesan            #+#    #+#             */
/*   Updated: 2021/05/27 21:11:18 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(unsigned int n)
{
	int cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	while (n != 1)
	{
		n /= 2;
		cnt++;
	}
	return (cnt);
}

int		ft_min(int a, int b)
{
	return (a < b) ? a : b;
}

int		ft_max(int a, int b)
{
	return (a > b) ? a : b;
}
