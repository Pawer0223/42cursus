/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:54:24 by taesan            #+#    #+#             */
/*   Updated: 2021/08/22 03:54:33 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//◦ export with no options
// ◦ unset with no options
//◦ env with no options or arguments
#include "../includes/minishell.h"

int	rebuild_envp(t_info *info, t_list **list)
{
	t_list	*list_temp;
	char	**envp;
	int		i;

	envp = (char **)malloc(sizeof(char *) * (info->envp_cnt + 1));
	if (!envp)
		return (0);
	envp[info->envp_cnt] = 0;
	i = 0;
	while (info->envp[i])
	{
		envp[i] = info->envp[i];
		i++;
	}
	ft_free(info->envp);
	list_temp = *list;
	while (list_temp)
	{
		envp[i] = (char *)(list_temp->content);
		list_temp = list_temp->next;
		i++;
	}
	info->envp = envp;
	return (1);
}

int	append_export_list(t_list **list, char *line)
{
	char	*content;
	t_list	*data;

	if (!line)
		return (0);
	line[ft_strlen(line) - 1] = '\n';
	content = ft_strdup(line);
	if (!content)
		return (0);
	data = ft_lstnew(content);
	if (!data)
	{
		ft_free(content);
		return (0);
	}
	ft_lstadd_back(list, data);
	return (1);
}
/*
	** envp에다가 .export.txt읽어서 붙인다.
*/
int		check_export_file(t_info *info, t_list **list)
{
	int		fd;
	char	*line;

	fd = open(EXPORT_FILE, O_RDONLY);
	if (fd != -1)
	{
		line = 0;
		while (get_next_line(fd, &line) > 0)
		{
			if (!append_export_list(list, line))
				return (0);
			info->envp_cnt++;
		}
		if (!append_export_list(list, line))
			return (0);
		info->envp_cnt++;
		if (line)
			ft_free(line);
		if (!rebuild_envp(info, list))
			return (0);
		ft_close(fd);
	}
	return (1);
}

int		builtin_env(t_info *info)
{
	char **envp;

	envp = info->envp;
	while (*envp)
	{
		ft_putendl_fd(*envp, info->std_out);
		envp++;
	}
	return (1);
}

int		print_export(t_info *info)
{
	char	**envp;
	int		j;
	int		visit;

	envp = info->envp;
	while (*envp)
	{
		ft_putstr_fd("declare -x ", info->std_out);
		j = 0;
		visit = 0;
		while ((*envp)[j])
		{
			ft_putchar_fd((*envp)[j], info->std_out);
			if ((*envp)[j] == '=' && !visit)
			{
				write(info->std_out, "\"", 1);
				visit = 1;
			}
			j++;
		}
		if (visit)
			ft_putendl_fd("\"", info->std_out);
		envp++;
	}
	return (1);	
}

int		builtin_unset(t_info *info)
{
	printf("ft_unset\n");
	return (0);
}
/*
	1. .export.txt파일을 읽은 후 info->envp를 rebuild한다.
	2. 정렬한다.
	3. 출력.
*/
int		builtin_export(t_info *info)
{
	int		i;
	char	**temp;
	t_list	*list;

	// just export !
	if (!info->param[1])
	{
		list = 0;
		if (check_export_file(info, &list))
		{
			temp = (char **)malloc(sizeof(char *) * (info->envp_cnt + 1));
			if (!temp)
				return (0);
			merge_sort(info->envp, temp, 0, info->envp_cnt - 1);
			ft_free(temp);
			print_export(info);
			ft_lstclear(&list, ft_free);
		}
	}
	// exist parameter => set
	else
	{
		i = 1;
		while (info->param[i])
		{
			// export a=B c=$d taesan
			// printf("param[%d] : [%s]\n", i, info->param[i]);
			int j = 0;
			char *param = info->param[i];
			char *key;
			char *value;
			key = 0;
			value = 0;
			while (param[j])
			{
				if (param[j] == '=')
				{
					key = ft_substr(param, 0, j);
					j++;
					int s = j;
					while (param[j] && param[j] != ' ')
						j++;
					value = ft_substr(param + s, 0, j - s);
					//printf("key : [%s], value : [%s]\n", key, value);
					break ;
				}
				j++;
			}
			if (key && value) // 파라미터에 = 형식이 있는 경우.
			{
				// key가 널인경우는 에러임. ex) a=b =c
				if (ft_strcmp(key, "") == 0 || is_empty(key))
					ft_putendl_fd("`%s: not a valid identifier", info->std_out);
				else
					printf("%s=\"%s\"\n", key, value);
			}
			else if (!key && !value) // =이 존재하지 않는 경우. 이 결과는 export에서만 출력되어야 함.
				printf("%s\n", param);
			ft_free(key);
			ft_free(value);
			i++;
		}	
	}
	return (1);
}

void	exec_builtin(int cmd, t_info *info)
{
	int r;

	if (cmd == EXPORT)
		r = builtin_export(info);
	else if (cmd == UNSET)
		r = builtin_unset(info);
	else if (cmd == ENV)
		r = builtin_env(info);
	if (!r)
		exit(EXEC_FAIL);
	exit(0);
}