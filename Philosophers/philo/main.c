#include "philo.h"

void	make_thread(t_program_data data, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		pthread_create(&data.threads[i], NULL, thread_main, &data.philos[i]);
		i++;
	}
	i = 0;
	while (i < cnt)
		pthread_join(data.threads[i++], NULL);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	cnt;
	t_program_data	data;

	ft_bzero(&data, sizeof(t_program_data));
	if (argc == 5 || argc == 6)
	{
		if (!init(&data, argv))
			return (0);
		make_thread(data, data.common.num_of_philo);
		clear_data(data);
	}
	else
		return (error_occur(PARAM_ERROR));


	return (0);
}