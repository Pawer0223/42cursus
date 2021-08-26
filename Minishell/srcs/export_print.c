/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 00:33:40 by taesan            #+#    #+#             */
/*   Updated: 2021/08/27 00:56:49 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	export_errror(char *param)
{
	write(STDERR_FILENO, "export: `", 10);
	ft_putstr_fd(param, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
	return (0);
}

int	print_export(t_info *info)
{
	char	**envp;
	int		j;
	int		visit;

	envp = info->envp;
	while (*envp)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		j = 0;
		visit = 0;
		while ((*envp)[j])
		{
			ft_putchar_fd((*envp)[j], STDOUT_FILENO);
			if ((*envp)[j] == '=' && !visit)
			{
				write(STDOUT_FILENO, "\"", 1);
				visit = 1;
			}
			j++;
		}
		if (visit)
			ft_putendl_fd("\"", STDOUT_FILENO);
		envp++;
	}
	return (1);	
}