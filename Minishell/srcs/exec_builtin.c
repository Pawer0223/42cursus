/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:54:24 by taesan            #+#    #+#             */
/*   Updated: 2021/08/23 02:30:46 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//◦ export with no options
// ◦ unset with no options
//◦ env with no options or arguments
#include "../includes/minishell.h"

void	write_new_line(int fd, char *key, char *value)
{
	ft_putstr_fd(key, fd);
	write(fd, "=", 1);
	ft_putstr_fd(value, fd);
}

int is_duplicate(char *line, char *key)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (!line[i] || key[i] != line[i])
			return (0);
		i++;
	}
	if (!line[i] || line[i] != '=')
		return (0);
	return (1);
}

int		evnp2_to_envp()
{
	int		fd;
	int		fd_2;
	char	*line;

	fd_2 = open(ENV_FILE_2, O_RDONLY, S_IRWXU);
	if (fd != -1)
	{
		fd = open(ENV_FILE, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		while (get_next_line(fd_2, &line) > 0)
			ft_putendl_fd(line, fd);
		ft_putstr_fd(line, fd);
		ft_free(line);
		ft_close(fd);
		ft_close(fd_2);
	}
	if (unlink(ENV_FILE_2) == -1)
		error_occur_std(UNLINK_ERR);
	return (1);
}

int	evnp_to_envp2(char *key, char *value)
{
	int		fd;
	int		visited;
	int		fd_2;
	char	*line;

	fd = open(ENV_FILE, O_RDONLY, S_IRWXU);
	if (fd != -1)
	{
		fd_2 = open(ENV_FILE_2, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		if (fd_2 == -1)
			return (error_occur_std(FILE_OPEN_ERR));	
		visited = 0;
		while (get_next_line(fd, &line) > 0)
		{
			if (!visited && is_duplicate(line, key))
			{
				visited = 1;
				write_new_line(fd_2, key, value);
			}
			else
				ft_putstr_fd(line, fd_2);
			ft_putchar_fd('\n', fd_2);
		}
		// 마지막 문자가 중복인지 체크한다. 중복이면 바꿔주면 끝이다.
		if (!visited && is_duplicate(line, key))
			write_new_line(fd_2, key, value);
		else
		{
			// 중복이 아니면, 마지막 놈을 쓴 다음에, visited를 안했을 때만 key, value값을 추가한다.
			ft_putstr_fd(line, fd_2);
			if (!visited)
			{
				ft_putchar_fd('\n', fd_2);
				write_new_line(fd_2, key, value);
			}
		}
		ft_free(line);
		ft_close(fd);
		ft_close(fd_2);
		if (unlink(ENV_FILE) == -1)
			error_occur_std(UNLINK_ERR);
	}
	return (1);
}

int	write_env_file(t_info *info, char *key, char *value)
{
	evnp_to_envp2(key, value);
	evnp2_to_envp();
	return (1);
}

int	export_add_var(char *param, char *key, char *value, t_info *info)
{
	int	fd;
	// 파라미터에 = 형식이 있는 경우. envp에 같다 붙인다.
	if (key && value)
	{
		// key가 널인경우는 에러임. ex) a=b =c
		// parent에서하게되면, 그냥 printf써도 무관 함.
		if (ft_strcmp(key, "") == 0 || is_empty(key))
		{
			write(info->std_out, "export: `", 10);
			ft_putstr_fd(param, info->std_out);
			ft_putendl_fd(": not a valid identifier", info->std_out);
		}
		else
			return (write_env_file(info, key, value));
			// printf("%s=\"%s\"\n", key, value);
	}
	else if (!key && !value) // =이 존재하지 않는 경우. 이 결과는 export에서만 출력되어야 함.
	{
		fd = open(EXPORT_FILE, O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
		if (fd == -1)
			return (error_occur_std(FILE_OPEN_ERR));
		// 쓰기전에 중복체크
		write(fd, param, ft_strlen(param));
		write(fd, "\n", 1);
		ft_close(fd);
		// printf("%s\n", param);
	}
	ft_free(key);
	ft_free(value);
	if ((key && !value) || (!key && value)) //substr에서 error된 결과가 들어온 경우
		return (0);
	return (1);
}

int	write_export(t_info *info)
{
	int	i;
	int j;
	int	s;
	int	r;
	char *param;

	i = 1;
	r = 1;
	while (r && info->param[i])
	{
		param = info->param[i];
		printf("param : [%s]\n", param);
		j = 0;
		while (param[j] && param[j] != '=')
			j++;
		s = j;
		while (param[j] && param[j] != ' ')
			j++;
		if (s != j)
			r = export_add_var(param, ft_substr(param, 0, s),\
			ft_substr(param + s + 1, 0, j - s), info);
		else
			r = export_add_var(param, 0, 0, info);
		i++;
	}
	return (r);
}

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
	if (ft_strlen(line) <= 1)
		line = ft_strjoin(line, " ");
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
	else
		return (write_export(info));
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