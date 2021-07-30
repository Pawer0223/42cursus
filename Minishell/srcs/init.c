/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:49:55 by taesan            #+#    #+#             */
/*   Updated: 2021/07/29 22:48:03 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
	따옴표 처리
*/
int	set_command_info(t_info *info, char *input)
{
	char	**input_sp;
	char	*cmd;
	char 	**temp;
	int		cmd_idx;

	input_sp = ft_split(input, ' ');
	if (!input_sp)
		return (error_occur_std(SPLIT_ERR));
	temp = ft_split(input_sp[0], '/');
	if (!temp)
		return (error_occur_std(SPLIT_ERR));
	cmd_idx = 0;
	while (temp[cmd_idx])
		cmd_idx++;
	info->is_builtin = check_builtin(temp[cmd_idx - 1]);
	split_free(temp);
	cmd = check_command(info->paths, input_sp[0], ft_strlen(input_sp[0]));
	if (cmd)
	{
		free(input_sp[0]);
		input_sp[0] = cmd;
	}
	info->param = input_sp;
	return (1);
}

/*
	pipe 존재하는지
	큰 따옴표나 작은 따옴표 존재하는지 && 홀 수 인경우 에러
	큰 따옴표, 작은 따옴표 동시에 존재하면, 먼저 어떤걸로 적용할지.
*/
void	set_input_info(t_info *info, char *input)
{
	while (*input)
	{
		if (*input == SINGLE_Q)
			info->single_q++;
		else if (*input == DOUBLE_Q)
			info->double_q++;
		else if (*input == PIPE)
			info->pipe_cnt++;
		if (info->single_q == 1 && info->double_q == 0)
			info->start_q = SINGLE_Q;
		else if (info->single_q == 0 && info->double_q == 1)
			info->start_q = DOUBLE_Q;
		input += 1;
	}
	/*
		이 경우, 문자열로 인식하도록 해야 함
	*/
	if ((info->start_q = SINGLE_Q && info->single_q % 2 != 0) || \
		(info->start_q = DOUBLE_Q && info->double_q % 2 != 0))
	{
		
	}	
}

int	init_info(t_info *info, char *input)
{
	char	*new_input;

	// parsing을 먼저해야겠다, 파이프라인 존재하면 pipe사용해야 하니깐.

	// n개의 명령어를 찾아야 함.

	new_input = input_space_filter(input, ft_strlen(input) + 1);
	if (!new_input)
		return (0);
	set_input_info(info, new_input);
	if (!set_command_info(info, new_input))
		return (0);
	ft_free(new_input);
	return (1);
}