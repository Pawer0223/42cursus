#include "philo.h"

void	to_string_common(t_common common)
{
	printf("num_of_philo : %d\n", common.num_of_philo);
	printf("time_to_die : %d\n", common.time_to_die);
	printf("time_to_eat : %d\n", common.time_to_eat);
	printf("time_to_sleep : %d\n", common.time_to_sleep);
	printf("time_each_must_eat : %d\n", common.time_each_must_eat);
	printf("start time : %lld\n", common.start);
}