#include "../includes/minishell.h"

void	space_filter(char **input, char *new_input, int len)
{
	int		s;
	int		e;
	int		idx;

	s = 0;
	idx = 0;
	while (s < len && (*input)[s])
	{
		e = s;
		// quotation은 스페이스를 유지하면서.
		// quotation을 지워준다.
		if (is_quotation((*input)[e]))
		{
			char c = (*input)[e];
			e++;
			while (e < len && (*input)[e] != c)
				new_input[idx++] = (*input)[e++];
			e++;
		}
		while (e < len && (*input)[e] == ' ')
			e++;
		if (e < len)
		{
			// 연속한 여러개의 스페이스는 ' '로 변경한다.
			if (s != e && s != 0 && (*input)[e])
				new_input[idx++] = ' ';
			if (is_quotation((*input)[e]))
				e--;
			else
				new_input[idx++] = (*input)[e];
		}
		s = e;
		s++;
	}
	free(*input);
	*input = new_input;
}

int		quote_filter(t_info *info, char **input, int s, int *e)
{
	int		dollar_idx;
	char	is_db_q;

	is_db_q = (*input)[s];
	// (*input)[s] = ' ';
	// (*input)[*e] = ' ';
	if (is_db_q == DOUBLE_Q)
	{
		dollar_idx = exist_dollar(*input, s, *e);
		if (dollar_idx)
		{
			if(!replace_env(info->envp, input, dollar_idx, e))
				return (0);
		}
	}
	return (1);
}

int	filter_input(t_info *info, char **input, int len)
{
	int		s;
	int		e;

	e = 0;
	while (e < len && (*input)[e])
	{
		if (is_quotation((*input)[e]))
		{
			s = e++;
			while ((*input)[e] && (*input)[e] != (*input)[s])
				e++;
			if (e < len && (*input)[s] == (*input)[e])
			{
				if (!quote_filter(info, input, s, &e))
					return (0);
			}
		}
		else if ((*input)[e] == DOLLAR)
		{
			if (!replace_env(info->envp, input, e, &e))
				return (0);
			len = ft_strlen(*input);
		}
		e++;
	}
	return (1);
}

// 앞 뒤로 자르기..
int	make_param(t_info *info, char *input)
{
	int		i;
	int		s;
	t_list	*list;
	t_list	*data;
	char	*content;

	i = 0;
	list = 0;
	s = 0;
	int len = ft_strlen(input);
	while (i < len && input[i])
	{
		content = 0;
		if (i < len && is_quotation(input[i]))
		{
			char c = input[i];
			i++;
			s = i;
			while (i < len && input[i] != c)
				i++;
			content = ft_substr(input + s, 0, i - s);
		}
		else if (i < len && input[i] == ' ')
		{
			content = ft_substr(input + s, 0, i - s);
			while (i < len && input[i] == ' ')
				i++;
			i--;
		}
		if (content)
		{
			data = ft_lstnew(content);
			ft_lstadd_back(&list, data);
			s = i + 1;
		}
		i++;
	}
	content = ft_substr(input + s, 0, i - s);
	data = ft_lstnew(content);
	ft_lstadd_back(&list, data);
	printf("s : %d, end : %d\n", s , i);
	i = 0;
	while (list)
	{
		printf("param[%d] : [%s]\n", i++, (char *)(list->content));
		list = list->next;
	}
	return (1);
}

int	command_filter(t_info *info, char **content)
{
	char	*new_input;
	int		len;

	len = ft_strlen((char *)(*content));
	if (!filter_input(info, content, len))
		return (error_occur_std(FILTER_INPUT_ERR));
	make_param(info, *content);
	len = ft_strlen((char *)(*content));
	new_input = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_input)
		return (error_occur_std(MALLOC_ERR));
	ft_memset(new_input, 0, len + 1);
	space_filter(content, new_input, len);
	return (1);
}