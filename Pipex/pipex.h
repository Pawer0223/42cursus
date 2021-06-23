/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:55:53 by taesan            #+#    #+#             */
/*   Updated: 2021/06/23 16:25:02 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#define STDIN_PIPE 0x1
#define STDOUT_PIPE 0x2
#define BUFFER_SIZE 256

#include "./libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include "pipex.h"

int		error_occur();
char	*set_path(char *envp[]);
int		pipe_input_set(int pipe_line[2], const char *file);
char	*check_command(const char *path, char *cmd, int len);
void	split_free(char **data);


#endif