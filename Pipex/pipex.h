/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:55:53 by taesan            #+#    #+#             */
/*   Updated: 2021/06/29 19:05:17 by taesan           ###   ########.fr       */
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
char	**set_path(char *envp[]);
char	*check_command(char **paths, char *cmd, int len);
void	split_free(char **data);
void	exec_command(t_pipe *info, int pipe[2], int flags, int is_last);
int		init_pipe(const char *input, const char *output, char *envp[], t_pipe *info);
int		set_param_info(t_pipe *info, const char *cmd, char **paths);
int		set_connect_pipe(t_pipe *info, int i);
int		pipe_input_set(int pipe_line[2], const char *file);

#endif