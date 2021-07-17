#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "defines.h"

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		error_occur(char *msg);

/*
	data
*/
int		init_param(t_param *common, char *argv[]);
int		init_philos(t_philo **philos, pthread_mutex_t **forks, t_param common);

/*
	thread
*/
void	*thread_main(void *arg);
/*
	free
*/
void	double_ptr_free(void **ptr, int end); 
void	clear_data(t_philo **p, pthread_mutex_t	**f, pthread_t	**ths, int cnt);

/*
	** test
*/
void	to_string_common(t_param common);

#endif