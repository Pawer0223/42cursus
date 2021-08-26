/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:54:24 by taesan            #+#    #+#             */
/*   Updated: 2021/08/27 00:31:07 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_builtin(int cmd, t_info *info)
{
	int r;

	if (cmd == EXPORT)
		builtin_export(info);
	else if (cmd == UNSET)
		builtin_unset(info);
	else if (cmd == ENV)
		builtin_env(info);
	exit(0);
}