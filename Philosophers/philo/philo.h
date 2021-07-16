#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "defines.h"

int		ft_atoi(const char *str);
int		error_occur(char *msg);
int		init_param(t_param *common, char *argv[]);
void	to_string_common(t_param *common);


#endif