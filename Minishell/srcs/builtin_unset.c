/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 00:23:58 by taesan            #+#    #+#             */
/*   Updated: 2021/08/27 00:24:14 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	builtin_unset(t_info *info)
{
	int	i;

	i = 1;
	while (info->param[i])
	{
		if (!remove_env_var(info->param[i]))
			exit(EXEC_FAIL);
		if (!temp_to_datafile(ENV_FILE_2, ENV_FILE))
			exit(EXEC_FAIL);
		if (!write_export_file(info->param[i], 1))
			exit(EXEC_FAIL);
		i++;
	}
	exit(0);
}