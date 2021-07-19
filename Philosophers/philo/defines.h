#ifndef DEFINES_H
# define DEFINES_H

#include "philo.h"

typedef struct	s_common
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_each_must_eat;
	long long start;
}				t_common;

typedef struct	s_philo
{
	int				seq;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_common		common;
	long long		last_time;
}				t_philo;

/*
	act를 시작한 시간.
*/
typedef	struct	s_timestamp
{
	long long start;
	long long take;
	long long eat;
	long long sleep;
	long long think;
	long long die;
}				t_timestamp;

typedef struct	s_program_data
{
	t_common	common;
	t_philo	*philos;
	pthread_mutex_t *forks;
	pthread_t	*threads;
}				t_program_data;

#define	PARAM_ERROR "parameter error"
#define	MALLOC_ERROR "malloc fail"
#define PRINT_TAKE "has taken a fork"
#define PRINT_EAT "is eating"
#define PRINT_SLEEP "is sleeping"
#define PRINT_THINK "is thinking"
#define PRINT_DIE "died"
#define ACT_EAT 1
#define ACT_TAKE 2
#define ACT_SLEEP 3
#define ACT_DIE 4
#define ACT_THINK 5
#define	MS 1000



#endif