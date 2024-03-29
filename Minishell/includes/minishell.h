/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:50:59 by taesan            #+#    #+#             */
/*   Updated: 2021/09/06 16:14:33 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>
# include "../libft/libft.h"
# include "defines.h"
/*
	error.c
*/
int		error_occur_perror(char *msg);
void	error_occur_perror_void(char *msg);
int		stderr_print(char *cmd, char *param, char *msg);
int		export_errror(char *param);
/*
	utils
*/
int		is_quotation(char c);
int		pass_possible(char c);
int		pass_possible_2(char c, int *e);
int		is_empty(char *temp);
int		is_redirect(char c);
int		is_double_symbol(int symbol);
void	ft_close(int fd);
void	jump_space(char *input, int *i);
void	clear_pipe(t_info *info, int pipe[2], int flags);
/*
	check
*/
int		check_builtin(char *cmd);
char	*check_command(char **paths, char *cmd, int len);
int		exist_dollar(char *input, int s, int e);
/*
	init
*/
int		init_command_info(t_info *info);
int		init_envp_and_signal(t_info *info, int ac, char *av[], char *en[]);
int		copy_envp(t_info *info);
void	clear_envp_info(t_info *info);
char	**init_path(char *envp[]);
/*
	sig_handler
*/
void	ctrl_d_handler(t_info *info);
void	sigint_handler(int signo);
void	sigint_occur(t_info *info);
/*
	using free
*/
void	split_free(char **data);
void	ft_free(void *data);
void	clear_all_data(t_info *info);
void	clear_data(t_info *info);
void	paths_clear(t_info *info);
/*
	exec
*/
void	exec_call(t_info *info, int instruct_seq);
/*
	make_command_list
*/
int		make_command_list(t_info *info, char *input);
int		append_command(t_info *info, char *input, int s, int e);
int		append_pipe_command(t_info *info, char *input, int *s, int *e);
int		append_amper_command(t_info *info, char *input, int *s, int *e);
/*
	filter
*/
int		command_filter(t_info *info, char **content);
int		redirect_filter(t_info *info, char **content);
int		redirect_get_end(char *content, int *e);
int		move_redirect_space(char *content, int *e, int idx);
int		move_redirect_and(char *content, int *e, int idx);
void	move_quot_point(char *line, int *e, char end_c);
/*
	replace_env
*/
int		replace_env(t_info *info, char **ptr, int s, int *next_idx);
/*
	redirect_util
*/
int		remove_redirect(int s, int e, char **content);
int		get_ampersand_fd(char *content, int i);
char	*get_right_str(char *content, int i);
void	redirection_dup_exec(int fds[2]);
/*
	gnl
*/
int		get_next_line(int fd, char **line);
char	*content_null(char *buf);
char	*check_first(int fd, char **line);
/*
	set_connect_pipe
*/
int		set_connect_pipe(t_info *info, int seq);
/*
	redirect_dup(int & out)
*/
int		redirect_in_dup(t_info *info, int std_in, char *content);
int		redirect_out_dup(int fds[2], char *content);
int		redirection_dup(t_info *info);
/*
	exec_builtin
*/
void	exec_builtin(int cmd, t_info *info);
/*
	sort
*/
void	merge_sort(char **sorted, char **temp, int idx_l, int idx_r);
/*
	make param
*/
int		make_param(t_info *info, char *input, int len);
/*
	write_env_file
*/
int		write_env_file(char *key, char *param);
int		remove_var(char *r_file, char *w_file, char *key);
/*
	builtin
*/
void	builtin_exit(t_info *info);
void	builtin_echo(t_info *info);
void	builtin_cd_sib(t_info *info);
void	builtin_cd_parent(t_info *info);
void	builtin_pwd(t_info *info);
void	builtin_env(t_info *info);
void	builtin_unset(t_info *info);
void	builtin_export(t_info *info);
void	builtin_set(t_info *info, int pipe[2]);
int		get_argc(char **argv);
/*
	export
*/
int		write_export_file(char *var);
int		print_export(t_info *info);
int		export_file_merge(t_info *info, t_list **list);
void	export_add_var(t_info *info);
int		env_file_cmp(const char *line, const char *key);
int		temp_to_datafile(char *read, char *write);
int		datafile_to_temp(char *r_file, char *w_file, char *key, char *param);
/*
	filter_asterisk
*/
int		filter_asterisk(t_info *info, int i);
/*
	list_to_string
*/
t_list	*list_to_string(t_info *info, char *input, int *i, int *s);
t_list	*front_back_join(char *input, t_strjoin *temp);
/*
	free_utils
*/
void	remove_file(void);
void	content_not_rm(void *param);
/*
	status_macro
*/
int		exit_status(int status);
int		term_status(int status);
/*
	special_positional_param
*/
int	special_positional_param(t_info *info, char **ptr, int s, int *next_idx);

#endif
