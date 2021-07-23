/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:19:34 by taesan            #+#    #+#             */
/*   Updated: 2021/06/30 19:27:40 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, const char *argv[], char *envp[])
{
	t_pipe	info;
	int		r;

	if (argc < 5)
		return (error_occur_std(PARAM_ERR));
	else
	{
		r = start(argc, argv, envp, &info);
		if (!r && unlink(argv[argc - 1]) == -1)
			return (error_occur_std(UNLINK_ERR));
		clear_info(&info);
	}
	return (r);
}
