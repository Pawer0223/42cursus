#ifndef DEFINES_H
# define DEFINES_H

#include "philo.h"

typedef struct	s_param
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_each_must_eat;
}				t_param;

typedef struct	s_philo
{
	int				seq;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_param			*common;
}				t_philo;

#define	PARAM_ERROR "parameter error"
#define	MALLOC_ERROR "malloc fail"
#define CREATE "has taken a fork"
#define EAT "is eating"
#define SLEEP "is sleeping"
#define THINK "is thinking"
#define DIE "died"
#define	MS 1000


#endif