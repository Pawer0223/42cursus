/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 21:17:51 by taesan            #+#    #+#             */
/*   Updated: 2021/08/07 22:02:14 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int get_fd(int s, int e, char *content)
{
	int fd;

	fd = 0;
	while (s < e)
	{
		fd = (fd * 10) + (content[s] - '0'); 
		s++;
	}
	return (fd);
}

char	*get_right_str(char *content, int *e)
{
	int		i;
	int		s;

	i = *e + 1;
	while (content[i] && content[i] == ' ')
		i++;
	s = i;
	while (content[i] && content[i] != ' ') // 단순히 스페이스로 넘겨도 되는지.. 예외 문자가 있을라나..
		i++;
	*e = i;
	return (ft_substr(content + s, 0, i - s));
}