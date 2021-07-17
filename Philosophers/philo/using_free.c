#include "philo.h"

void	double_ptr_free(void **ptr, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		free(ptr[i++]);
		ptr[i] = 0;
	}
	free(ptr);
	ptr = 0;	
}

void	clear_philo(t_philo *p)
{
	if (!p)
		return ;
	if (p->common)
		free(p->common);
	ft_bzero(p, sizeof(p));
	free(p);
	p = 0;
}

void	clear_data(t_philo **p, pthread_mutex_t	**f, pthread_t	**ths, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		clear_philo(p[i]);
		pthread_mutex_destroy(f[i]);
		if (ths[i])
			free(ths[i]);
		if (f[i])
			free(f[i]);
		ths[i] = 0;
		f[i] = 0;	
		i++;
	}
	if (p)
		free(p);
	if (f)
		free(f);
	if (ths)
		free(ths);
	p = 0;
	f = 0;
	ths = 0;
}