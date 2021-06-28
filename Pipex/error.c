#include "pipex.h"

int			error_occur_perror(char *msg)
{
	perror(msg);
	return (0);
}

int			error_occur_std(char *msg)
{
	ft_putendl_fd(msg, 1);
	return (0);
}