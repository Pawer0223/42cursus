#include "../includes/minishell.h"

int		file_open_getfd(char *content, int *e)
{
	char	*file_nm;
	int		fd;

	file_nm = get_right_str(content, e);
	if (!file_nm)
		return (0);
	fd = open(file_nm, O_RDONLY);
	ft_free(file_nm);
	if (fd == -1)
		return (error_occur_perror(INPUT_OPEN_ERR));
	return (fd);
}

int	set_right_fd_in(t_redirect_in *data, char *content, int *e)
{
	int		i;
	int		s;
	int		fd;

	i = *e + 1;
	while (content[i] && content[i] == ' ')
		i++;
	if (content[i] == '&')
	{
		i++;
		s = i;
		while (content[i] && ft_isdigit(content[i]))
			i++;
		data->right_fd = get_fd(s, i, content);
		*e = i;
	}
	else
	{
		data->right_fd = file_open_getfd(content, e);
		if (!data->right_fd)
			return (0);
	}
	return (1);
}

/*
	왼쪽대상 찾기. 바로옆에 딱 붙어서 숫자여야 함.
*/
void	set_left_fd_in(t_redirect_in *data, char *content, int *s)
{
	int i;
	int	end;
	int fd;
	
	i = *s - 1;
	fd = 0;
	while(i >= 0 && ft_isdigit(content[i]))
		i--;
	if (i < *s - 1 && (i < 0 || (i >= 0 && content[i] == ' ')))
	{
		data->left_fd = get_fd(i + 1, *s, content);
		*s = i + 1;
	}
}
/*
	현재 content의 start부터 좌, 우로 입출력 변경 대상을 찾고
	list에 추가해준다.
*/
int	redirect_in_add(t_list **target, char **content, int s, char dir)
{
	int				e;
	t_list			*data;
	t_redirect_in	*redirect;

	e = s;
	redirect = (t_redirect_in *)malloc(sizeof(t_redirect_in));
	if (!redirect)
		return (0);
	ft_bzero(redirect, sizeof(t_redirect_in));
	data = ft_lstnew(redirect);
	if (!data)
		return (0);
	redirect->left_fd = 0;
	e = s;
	printf("===== ===== before ===== =====\n");
	printf("left : %d, right : %d\n", redirect->left_fd, redirect->right_fd);
	printf("s : [%d], e : [%d]\n", s, e);
	set_left_fd_in(redirect, *content, &s);
	if ((*content)[e + 1] && dir == (*content)[e + 1])
	{
		e++;
		redirect->limiter = get_right_str(*content, &e);
		if (!redirect->limiter)
			return (0);
	}
	else
		set_right_fd_in(redirect, *content, &e);
	printf("===== ===== after ===== =====\n");
	printf("left : %d, right : %d\n", redirect->left_fd, redirect->right_fd);
	printf("s : [%d], e : [%d]\n", s, e);
	printf("limiter : [%s]\n", redirect->limiter);

	char *left = ft_substr(*content, 0, s);
	char *right = ft_substr(*content + e, 0, ft_strlen(*content) - e);
	char *new_input = ft_strjoin(left, right);

	printf("left : [%s], right : [%s], new : [%s]\n", left, right, new_input);
	// substr(0, s) + substr(e, len)
	return (1);
}