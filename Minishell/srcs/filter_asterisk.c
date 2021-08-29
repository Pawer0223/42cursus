/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_asterisk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 01:25:08 by taesan            #+#    #+#             */
/*   Updated: 2021/08/29 19:25:04 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		pattern_check(char *pattern, char *line)
{
	int	i;
	int	j;

	i = 0;
	if (line[i] == '.')
		return (0);
	j = 0;
	while (pattern[i])
	{
		if (pattern[i] && pattern[i] == '*')
		{
			while (pattern[i] && pattern[i] == '*')
				i++;
			// *이후에 별다른 문자가 없다면, 가능한 패턴임.
			if (!pattern[i])
				return (1);
			// *다음의 문자가 나오기전까지는 허용 가능.
			while (line[j] && line[j] != pattern[i])
				j++;
		}
		if (pattern[i] != line[j] || (pattern[i] && !line[j]))
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	*temp(t_list *list)
{
	char *new_content;

	new_content = 0;
	return (new_content);
}

char	*make_asterisk_str(char *content)
{
	DIR				*dir_ptr = NULL;
	struct dirent	*file = NULL;
	t_list			*list;
	t_list			*data;
	int				i;

	printf("asterisk content : [%s]\n", content);
	dir_ptr = opendir(".");
	if (!dir_ptr)
		printf("null\n");
	else
	{
		while((file = readdir(dir_ptr)) != NULL) 
		{
			if (pattern_check(content, file->d_name))
			{
				printf("is pattern : [%s], line :[%s]\n", content, file->d_name);
			}
		}
		closedir(dir_ptr);
	}
	return (temp(list));
}

int	filter_asterisk(t_info *info)
{
	char	**temp;
	char	*new_content;
	int		i;
	int		j;

	temp = info->param;
	new_content = 0;
	i = 1;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (temp[i][j] == '*')
			{
				new_content = make_asterisk_str(temp[i]);
				if (!new_content)
					return (0);
				ft_free(temp[i]);
				temp[i] = new_content;
				break ;
			}
			j++;
		}
		i++;
	}
	return (1);
}