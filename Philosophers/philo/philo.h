#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "defines.h"

/*
	error
*/
int			error_occur(char *msg);
/*
	utils
*/
int			ft_atoi(const char *str);
void		ft_usleep(long long end_time);
/*
	init
*/
int			init(t_program_data *data, char *argv[]);
/*
	thread
*/
void		*philosopher(void *arg);
void		*monitor(void *arg);
/*
	** test
*/
void		to_string_common(t_common common);
/*
	** time
*/
long long	get_curr_time(void);

#endif
