#include "philo.h"

int	make_thread(t_program_data data, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		printf("philos[%d]->seq : %d\n", i, data.philos[i]->seq);
		pthread_create(data.threads[i], NULL, thread_main, data.philos[i]);
		i++;
	}
	i = 0;
	while (i < cnt)
		pthread_join(*data.threads[i++], NULL);
	return (1);
	
}

int	main(int argc, char *argv[])
{
	int	i;
	int	cnt;
	t_program_data	data;

	ft_bzero(&data, sizeof(t_program_data));
	if (argc < 5)
		return (error_occur(PARAM_ERROR));
	// param error
	if (!init_param(&data.common, argv))
		return (error_occur(PARAM_ERROR));
	cnt = data.common.num_of_philo;
	if (!program_data_malloc(&data, cnt))
		return (clear_data(data, cnt));
	// set fork
	init_philos(data, cnt);
	// make thread
	make_thread(data, cnt);
	// to_string_common(common);
	// destroy fork -> pthread_mutex_destroy(philo[i].left);
	clear_data(data, cnt);

	return (0);
}