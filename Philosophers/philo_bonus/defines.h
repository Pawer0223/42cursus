#ifndef DEFINES_H
# define DEFINES_H

# include "philo.h"

typedef struct s_common
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_each_must_eat;
	long long	start;
	sem_t		*finish_sem;
	sem_t		*forks;
	sem_t		*must_eat_sem;
}				t_common;

typedef struct s_philo
{
	int				pid;
	int				seq;
	int				eat_cnt;
	sem_t			*status;
	t_common		*common;
	long long		last_time;
}				t_philo;

typedef struct s_program_data
{
	t_common	common;
	t_philo		*philos;
}				t_program_data;

# define SEM_FINISH "finish"
# define SEM_FORKS "forks"
# define SEM_MUST_EAT "musteat"
# define	PARAM_ERROR "parameter error"
# define	MALLOC_ERROR "malloc fail"
# define PRINT_TAKE "has taken a fork"
# define PRINT_EAT "is eating"
# define PRINT_SLEEP "is sleeping"
# define PRINT_THINK "is thinking"
# define PRINT_DIE "died"
# define ACT_EAT 1
# define ACT_TAKE 2
# define ACT_SLEEP 3
# define ACT_DIE 4
# define ACT_THINK 5
# define	MS 1000

#endif
