#include "philo.h"



void	understand_usleep()
{
	int i = 0;

	unsigned int sec;

	while (i < 10) {
		useconds_t sec = SECOND + 10000;
		int result = usleep(sec);
		printf("i : %d, result : %d\n", i, result);
		i++;
	}
}

void	test_1() {

	int param_1 = 2; // number_of_philosophers
	int param_2 = 5; // time_to_die
	int param_3 = 2; // time_to_eat
	int param_4 = 2; // time_to_sleep
	int param_5 = 10; //[number_of_times_each_philosopher_must_eat]

	understand_usleep();



}