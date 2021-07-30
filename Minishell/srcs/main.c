/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:00:23 by taesan            #+#    #+#             */
/*   Updated: 2021/07/29 21:25:50 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	start(t_info *info, char *input)
{

	if (!init_info(info, input))
		return (0);
	if (info->pipe_cnt > 0)
	{
		printf("pipe 코드 타도록 !\n");
	}
	else
	{
		exec_command(info, 0, 0, 0);
	}
	return (0);
}

int main(int argc, char *argv[], char *envp[])
{
	char	*input;
	char	*prompt;
	t_info	info;

	// 설정의 PS1, PS2로 받아올 수 있도록. ?
	prompt = "$";
	// 종료 시그널 받으면 프로그램 끝내야 함.

	ft_bzero(&info, sizeof(t_info));
	info.paths = set_path(envp);
	if (!info.paths)
		return (error_occur_std(SPLIT_ERR));
	info.envp = envp;
	while(1)
	{
		input = readline(prompt);
		if (ft_strcmp(input, "") != 0)
		{
			add_history(input);
			if (start(&info, input))
				break ;
		}
		ft_free(input);
	}
	// clear heap
}