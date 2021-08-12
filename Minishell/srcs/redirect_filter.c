#include "../includes/minishell.h"

int	redirect_filter(t_info *info, char **content)
{
	int i;

	i = 0;
	while ((*content)[i])
	{
		if (is_redirect((*content)[i]))
		{
			if ((*content)[i] == REDIRECT_IN && \
				!redirect_in_add(info, content, i, REDIRECT_IN))
					return (0);
			else if ((*content)[i] == REDIRECT_OUT && \
				!redirect_out_add(info, content, i, REDIRECT_OUT))
					return (0);
			i = -1;
		}
		i++;
	}
	return (1);
}