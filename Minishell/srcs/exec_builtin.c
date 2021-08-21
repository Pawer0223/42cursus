/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:54:24 by taesan            #+#    #+#             */
/*   Updated: 2021/08/22 02:22:30 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//◦ export with no options
// ◦ unset with no options
//◦ env with no options or arguments
#include "../includes/minishell.h"

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

	// envp에다가 .export.txt읽어서 붙인다.
	int		fd;
	char	*line;

	fd = open(EXPORT_FILE, O_RDONLY);
	if (fd != -1)
	{
		line = 0;
		while (get_next_line(fd, &line) > 0)
			printf("[%s]\n", line);
		printf("last ==> [%s]\n", line);
		if (line)
			ft_free(line);
		ft_close(fd);
	}
	// envp = info->envp;
	// while (*envp)
	// {
	// 	ft_putstr_fd("declare -x ", info->std_out);
	// 	j = 0;
	// 	visit = 0;
	// 	while ((*envp)[j])
	// 	{
	// 		ft_putchar_fd((*envp)[j], info->std_out);
	// 		if ((*envp)[j] == '=' && !visit)
	// 		{
	// 			write(info->std_out, "\"", 1);
	// 			visit = 1;
	// 		}
	// 		j++;
	// 	}
	// 	if (visit)
	// 		ft_putendl_fd("\"", info->std_out);
	// 	envp++;
	// }
	return (1);	
}

int		builtin_unset(t_info *info)
{
	printf("ft_unset\n");
	return (0);
}
/*
	$해석하도록 해야 함.
	정렬해야 함..
	export할 때는, 특정파일에 저장하고, parent에서 append로직

	특수문자 기호처리.. ? *이나, &나 =과 같은경우..

	a=c=b 
		a="c=b"

	a=c= b
		a="c="
		b

	a= =b
		a=""
*/
int		builtin_export(t_info *info)
{
	int		i;
	char	**temp;

	// if (!info->param[1])
	// {
	// 	temp = (char **)malloc(sizeof(char *) * (info->envp_cnt + 1));
	// 	if (!temp)
	// 		return (0);
	// 	merge_sort(info->envp, temp, 0, info->envp_cnt - 1);
	// 	//ft_free(temp);
	// 	print_export(info);
	// 	// 그냥 출력.
	// 	// builtin_env(info);
	// }
	// else
	// {
	// 	i = 1;
	// 	while (info->param[i])
	// 	{
	// 		// export a=B c=$d taesan
	// 		// printf("param[%d] : [%s]\n", i, info->param[i]);
	// 		int j = 0;
	// 		char *param = info->param[i];
	// 		char *key;
	// 		char *value;
	// 		key = 0;
	// 		value = 0;
	// 		while (param[j])
	// 		{
	// 			if (param[j] == '=')
	// 			{
	// 				key = ft_substr(param, 0, j);
	// 				j++;
	// 				int s = j;
	// 				while (param[j] && param[j] != ' ')
	// 					j++;
	// 				value = ft_substr(param + s, 0, j - s);
	// 				//printf("key : [%s], value : [%s]\n", key, value);
	// 				break ;
	// 			}
	// 			j++;
	// 		}
	// 		/*
	// 			not a valid경우만제외하고, 
	// 			printf에 출력되는 정보를 파일에 write한다.
	// 			but, 변수만 선언된 경우에는 env에서는 출력x export에서는 출력되어야 한다
	// 			 이거 어떻게 잡냐

	// 			 변수를 따로 관리한다..

	// 			 export.
	// 			  => .export.txt

	// 			 env
	// 			  => .env.txt

	// 			다 끝나고 parent에서 해당파일을 각각 읽어서 write 해준다.
	// 			.env.txt는 두 변수 모두 붙인다.
	// 			.export는 export에만 붙인다.
				

	// 		*/
	// 		if (key && value) // 파라미터에 = 형식이 있는 경우.
	// 		{
	// 			// key가 널인경우는 에러임. ex) a=b =c
	// 			if (ft_strcmp(key, "") == 0 || is_empty(key))
	// 				printf("`%s: not a valid identifier\n", param);
	// 			else
	// 				printf("%s=\"%s\"\n", key, value);
	// 		}
	// 		else if (!key && !value) // =이 존재하지 않는 경우. 이 결과는 export에서만 출력되어야 함.
	// 			printf("%s\n", param);
	// 		ft_free(key);
	// 		ft_free(value);
	// 		i++;
	// 	}	
	// }
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