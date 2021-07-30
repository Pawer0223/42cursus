#include "../includes/minishell.h"

char	*space_filter(char *input, int len)
{
	int		s;
	int		e;
	int		idx;
	char	*new_input;

	new_input = (char *)malloc(sizeof(char) * (len + 1));
	ft_memset(new_input, 0, len + 1);
	if (!new_input)
		error_occur_std(MALLOC_ERR);
	s = 0;
	idx = 0;
	while (new_input && input[s])
	{
		e = s;
		while (input[e] && input[e] == ' ')
			e++;
		if (s != e && s != 0 && input[e])
			new_input[idx++] = ' ';
		new_input[idx++] = input[e];
		if (s != e)
			s = e;
		s++;
	}
	return (new_input);
}



void	change_quotation(char **envp, char **ptr, int s, int *e)
{
	char	*new_input;
	int		temp;

	if ((*ptr)[s] == SINGLE_Q)
	{
		(*ptr)[s] = ' ';
		(*ptr)[*e] = ' ';
		return ;
	}
	while ((*ptr)[s])
	{
		if ((*ptr)[s] == DOLLAR)
		{
		}
		s++;
	}
}

void	temp_func(t_info *info, char *input)
{
	int		s;
	int		e;

	e = 0;
	while (input[e])
	{
		if (is_quotation(input[e]))
		{
			s = e++;
			while (input[e] && input[e] != input[s])
				e++;
			printf("before : [%s]\n", input);
			if (input[s] == input[e])
				change_quotation(info->envp, &input, s, &e);
			printf("after : [%s]\n", input);
		}
		if (input[e] == DOLLAR)
		{
		}
		e++;
	}
}


int	command_filter(t_info *info)
{
	char	*temp;
	int		len;

	while (info->commands)
	{
		printf("cmd : [%s]\n", info->commands->content);
		// len = ft_strlen((char *)info->commands->content);
		// temp = space_filter(info->commands->content, len);
		// if (!temp)
		// 	return (error_occur_std(MALLOC_ERR));
		temp_func(info, info->commands->content);
		info->commands = info->commands->next;
	}
	return (0);
}