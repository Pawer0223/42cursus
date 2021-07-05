/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:55:53 by taesan            #+#    #+#             */
/*   Updated: 2021/07/05 20:20:09 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "./libft/libft.h"
#include "defines.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <stdio.h>

int		error_occur_perror(char *msg);
int		error_occur_std(char *msg);

char	*check_command(char **paths, char *cmd, int len);

int		exec_call(t_pipe *info, const char *param, char **paths, int is_last);

int		clear_info(t_pipe *info);
void	split_free(char **data);

int		init_pipe(const char *input, const char *output, char *envp[], t_pipe *info);
int		set_connect_pipe(t_pipe *info, int i);
int		set_param_info(t_pipe *info, const char *cmd, char **paths);
char	**set_path(char *envp[]);

int		start(int argc, const char *argv[], char *envp[], t_pipe *info);

#endif