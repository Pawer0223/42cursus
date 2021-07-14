#include "understand.h"

#define SIZE 3

typedef struct	s_per_mutex
{
	int				idx;
	int				*fork;
	int				*left;
	int				*right;
	pthread_mutex_t	mutex;
}				t_per_mutex;

void	to_string(t_per_mutex *per)
{
	printf("my : %d, left : %d, right : %d\n", *per->fork, *per->left, *per->right);
}

void	*thread_main_mutex(void	*arg)
{
	t_per_mutex *mut = (t_per_mutex *)arg;

	int cnt = 0;
	while (cnt < 3)
	{
		//pthread_mutex_lock(&mut->mutex);
		printf("########## Thread [%d] ##########\n", mut->idx);
		*mut->fork += mut->idx;
		*mut->left += mut->idx;
		*mut->right += mut->idx;
		to_string(mut);
		usleep(MS * MS * 1);
		cnt++;
		//pthread_mutex_unlock(&mut->mutex);
	}
	//printf("--- Thread [%d] ---\n", mut->idx);
	return (0);
}

/*
	Thread [0, ]
*/
void	undestand_mutex()
{
	int			key[SIZE] = {0, 0, 0};
	pthread_t	threads[SIZE];
	t_per_mutex	mutexs[SIZE];

	for (int i = 0; i < SIZE; i++) {
		mutexs[i].idx = i;
		mutexs[i].fork = &key[i];
		if (i == 0)
			mutexs[i].left = &key[SIZE - 1];
		else
			mutexs[i].left = &key[i - 1];

		if (i == SIZE - 1)
			mutexs[i].right = &key[0];
		else
			mutexs[i].right = &key[i + 1];

		pthread_mutex_init(&mutexs[i].mutex, NULL);
		pthread_create(&threads[i], NULL, thread_main_mutex, (void *)&mutexs[i]);
	}

	for (int i = 0; i < SIZE; i++) {
		pthread_join(threads[i], NULL);
	}

	for (int i = 0; i < SIZE; i++) {
		printf("key[%d] : %d", i, key[i]);
		if (i != SIZE - 1)
			printf(", ");
		else
			printf("\n");
	}
}