/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:05:24 by taesan            #+#    #+#             */
/*   Updated: 2021/07/05 20:20:28 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define READ_FD_IDX 0
# define WRITE_FD_IDX 1
# define STDIN_PIPE 0x1
# define STDOUT_PIPE 0x2
# define BUFFER_SIZE 256
# define PATH "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"
# define SPLIT_ERR "ft_split Error"
# define PARAM_ERR "Please Call [./pipex file1 \"cmd1\" \"cmd2\" file2]"
# define PARAM_ERR_BONUS "Call [./pipex here_doc LIMITER \"cmd1\" \"cmd2\" file]"
# define INPUT_OPEN_ERR "input file open"
# define OUTPUT_OPEN_ERR "output file open"
# define COMMAND_NOT_EXIST "command program not exist"
# define ENV_PATH_NOT_EXIST "system env PATH not exist"
# define DUP2_ERR "dup2"
# define ENV_PATH_NOT_EXIST "system env PATH not exist"
# define PIPE_ERR "create pipe Error"
# define READ_ERR "read result [-1]"
# define UNLINK_ERR "file remove Error"
# define HERE_DOC "here_doc"
# define WAIT_ERR "wait func return error [-1]"
# define TEMP_FILE ".temp.txt"

typedef struct s_pipe
{
	char		**param;
	char		**envp;
	const char	*out_file;
	int			pipe_in[2];
	int			pipe_out[2];
	int			connect_pipe[2];
	int			result_fd;
}				t_pipe;

#endif
