/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:16:03 by taesan            #+#    #+#             */
/*   Updated: 2021/06/22 21:16:47 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char	*set_path(char *envp[])
{
	char *path;

	while (*envp)
	{
		path = *envp;
		if (ft_strlen(path) < 4)
			continue;

		if (path[0] == 'P' && path[1] == 'A' && path[2] == 'T' && path[3] == 'H')
		{
			path = *envp;
			return (path);
		}
		envp++;
	}
	return (0);
}

int		pipe_input_set(int pipe_line[2], const char *file)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (error_occur());
	// 표준입력을, 파이프의 출력과 연결한다.

	pipe_line = 0;
	file = 0;


	return (1);
}