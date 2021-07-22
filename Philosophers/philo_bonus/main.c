#include "philo.h"

void	clear_data(t_program_data data, int cnt)
{
	int	i;
	int	status;

	i = 0;
	while (i < cnt)
		waitpid(data.philos[i++].pid, &status, 0);
	i = 0;
	while (i < cnt)
		sem_close(data.philos[i++].status);
	free(data.philos);
	data.philos = 0;
	sem_close(data.common.finish_sem);
	sem_close(data.common.muset_eat_sem);
	sem_close(data.common.forks);
}

void	make_process(t_program_data data, int cnt, int argc)
{
	int			i;
	int			pid;
	pthread_t	finish_th;
	pthread_t	must_eat_th;

	i = 0;
	while (i < cnt)
	{
		pid = fork();
		if (pid == 0)
			return (philosopher(&data.philos[i]));
		else if (pid < 0)
		{
			printf("Error: fork error\n");
			exit(1);
		}
		data.philos[i].pid = pid;
		i++;
	}
	if (argc == 6)
		pthread_create(&must_eat_th, NULL, must_eat_monitor, &data);
	pthread_create(&finish_th, NULL, philosopher_died, &data);
}

int	main(int argc, char *argv[])
{
	t_program_data	data;

	memset(&data, 0, sizeof(data));
	if (argc == 5 || argc == 6)
	{
		if (!init(&data, argv))
			return (0);
		make_process(data, data.common.num_of_philo, argc);
		clear_data(data, data.common.num_of_philo);
	}
	else
		return (error_occur(PARAM_ERROR));
	return (0);
}
