#include "pipex.h"

int			error_occur()
{
	perror(strerror(errno));
	return (0);
}