#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <sys/time.h>
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
int	init(t_program_data *data, char *argv[]);

/*
	thread
*/
void	*philosopher(void *arg);
/*
	free
*/
int		clear_data(t_program_data data);
/*
	** test
*/
void	to_string_common(t_common common);
/*
	** time
*/
long long	get_curr_time();

#endif