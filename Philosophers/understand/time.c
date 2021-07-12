#include "understand.h"

void	time_loop(int t)
{
	useconds_t remain = t * MS;

	int sec = t / MS;
	int usec = (t * MS) - (sec * (MS * MS));

	printf("sec : %d, usec : %d\n", sec, usec);
	usleep(remain);
}

void	undestand_time()
{
	printf("time\n");

	struct timeval tv;

	int t = 1000;

	int prev = 0;
	for (int i = 0; i < 10; i++) {
		gettimeofday(&tv, 0);
		printf("sec : %ld, usec : %d, usec diff : %d\n", tv.tv_sec, tv.tv_usec, tv.tv_usec - prev);
		time_loop(1500);
		prev = tv.tv_usec;
	}
}