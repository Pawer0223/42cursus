// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main_annotation.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/06/22 21:19:34 by taesan            #+#    #+#             */
// /*   Updated: 2021/06/28 21:38:03 by taesan           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pipex.h"

// int		clear_info(t_pipe *info)
// {
// 	int i;

// 	i = 0;
// 	while (i < 2)
// 	{
// 		if (info->pipe_in[i] > 0)
// 			close(info->pipe_in[i]);
// 		if (info->pipe_out[i] > 0)
// 			close(info->pipe_out[i]);
// 		i++;
// 	}
// 	if (info->result_fd > 0)
// 		close(info->result_fd);
// 	return (0);
// }

// char	**get_cmd_info(const char *cmd, char *path)
// {
// 	char	**cmd_info;

// 	if (!(cmd_info = ft_split(cmd, ' ')))
// 	{
// 		error_occur_std(SPLIT_ERR);
// 		return (0);
// 	}
// 	if (!(cmd_info[0] = check_command(path + 5, cmd_info[0], ft_strlen(cmd_info[0]))))
// 	{
// 		split_free(cmd_info);
// 		error_occur_std(COMMAND_NOT_EXIST);
// 		return (0);
// 	}
// 	return (cmd_info);
// }

// int		start(int argc, const char *argv[], char *envp[], t_pipe *info)
// {
// 	if (!init_pipe(argv[1], argv[argc - 1], envp, info))
// 		return (0);
// 	if (!(info->param = get_cmd_info(argv[2], info->path)))
// 		return (0);
// 	exec_command(info, info->connect_pipe, STDIN_PIPE | STDOUT_PIPE, 0);
// 	if (!(info->param = get_cmd_info(argv[argc - 2], info->path)))
// 		return (0);
// 	exec_command(info, info->pipe_out, STDIN_PIPE | STDOUT_PIPE, 1);
// 	return (1);
// }

// int		start_multi(int argc, const char *argv[], char *envp[], t_pipe *info)
// {
// 	int	i;

// 	// 이건 시작, 파일 정보를 읽어 in[1]을 채운다.(in[1] 닫음)
// 	if (!init_pipe(argv[1], argv[argc - 1], envp, info))
// 		return (0);
// 	if (!(info->param = get_cmd_info(argv[2], info->path)))
// 		return (0);
// 	// in에서 읽어 out으로 내보낸다.
// 	// 실행하면 in[0]닫고, out[1]닫음.. 남은건 out[0] => 즉, out에 데이터를 채움.
// 	// exec_command(info, info->connect_pipe, STDIN_PIPE | STDOUT_PIPE, 0);
// 	i = 2;
// 	while (i < argc - 2)
// 	{
// 		/*
// 			2번째, out에서 읽어 in으로 내보낸다.
// 				- 명령어 2개짜리(기본 subject)는, out에 저장된 데이터를 file로 저장하면 끝.
// 			3번째, in에서 읽어 out으로 내보낸다.
// 			...
// 		*/
// 		if (i > 2 && !(info->param = get_cmd_info(argv[i], info->path)))
// 			return (0);
	
// 		if (i % 2 != 0)
// 			info->pipe_in[0] = info->pipe_out[0];
// 		pipe(info->pipe_out); // 예외처리.
// 		if (pipe(info->pipe_out) == -1)
// 			return (0);
// 		// 2. 연결용 파이프 
// 		info->connect_pipe[0] = info->pipe_in[0];
// 		info->connect_pipe[1] = info->pipe_out[1];
// 		if (i % 2 != 0)
// 			exec_command(info, info->connect_pipe, STDIN_PIPE | STDOUT_PIPE, 0);
// 		else
// 			exec_command(info, info->connect_pipe, STDIN_PIPE | STDOUT_PIPE, 0);
// 		i++;
// 	}
// 	// 종료 됐을 때, in은 닫혀있을 것이다. 마지막에 out에서 읽어서 file로 출력하면 됨.
// 	if (!(info->param = get_cmd_info(argv[argc - 2], info->path)))
// 		return (0);
// 	exec_command(info, info->pipe_out, STDIN_PIPE | STDOUT_PIPE, 1);
// 	return (1);
// }


// /*
// 	** file1, cmd1, cmd2, file2
// 	ex) ./pipex ls.txt "grep zip" "wc -l" result.txt

// 	** multiple...
// 	ex) ./pipex ls.txt "grep zip" "grep u" "wc -l" result.txt
// */
// int		main(int argc, const char *argv[], char *envp[])
// {
// 	t_pipe	info;

// 	if (argc < 5)
// 		return (error_occur_std(PARAM_ERR));
// 	else
// 	{
// 		if (!start_multi(argc, argv, envp, &info))
// 			clear_info(&info);
// 	}
// 	return (1);
// }
