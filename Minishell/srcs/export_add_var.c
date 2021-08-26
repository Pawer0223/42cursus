#include "../includes/minishell.h"

int	write_export_substr(t_info *info, char *param, int j)
{
	char	*key;
	char	*value;
	int		r;

 	key = ft_substr(param, 0, j);
	value = ft_substr(param + j + 1, 0, ft_strlen(param) - j);
	r = 1;
	if (key && value)
	{
		if (ft_strcmp(key, "") == 0 || is_empty(key))
			export_errror(param);
		else
			r = write_env_file(info, key, value);
		if (r)
			r = write_export_file(key, 1);
	}
	ft_free(key);
	ft_free(value);
	if ((key && !value) || (!key && value))
		return (0);
	return (r);
}

void	export_add_var(t_info *info)
{
	int	i;
	int j;
	int	r;
	char *param;

	i = 1;
	r = 1;
	while (r && info->param[i])
	{
		param = info->param[i];
		j = 0;
		while (param[j] && param[j] != '=')
			j++;
		if (param[j] == '=')
			r = write_export_substr(info, param, j);
		else if (is_empty(param))
			r = export_errror(param);
		else
			r = write_export_file(param, 0);
		i++;
	}
	if (r)
		exit(0);
	exit(EXEC_FAIL);
}