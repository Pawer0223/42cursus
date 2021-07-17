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
//int		init_philos(t_philo **philos, pthread_mutex_t **forks, t_param common);
void	init_philos(t_program_data data, int cnt);


/*
	thread
*/
void	*thread_main(void *arg);
/*
	free
*/
int		clear_data(t_program_data data, int end);
/*
	malloc
*/
int	program_data_malloc(t_program_data	*data, int cnt);
/*
	** test
*/
void	to_string_common(t_param common);

#endif