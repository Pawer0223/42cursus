#include "understand.h"


void	undestand_time()
{
	printf("time\n");

	struct timeval start;
	struct timeval curr;


	int t = 1000;

	int prev = 0;

	gettimeofday(&start, NULL);
	long long s = start.tv_sec * MS + start.tv_usec / MS;
	for (int i = 0; i < 10; i++) {
		usleep(500000);
		gettimeofday(&curr, NULL);
		long long c = curr.tv_sec * MS + curr.tv_usec / MS;
		printf("start time : [%lld], curr time : [%lld], working time : [%lld]ms\n", s, c, (c - s));
		
		// printf("start : %ld, curr : %ld, working : %ldms\n", start.tv_sec, curr.tv_sec, (curr.tv_sec - start.tv_sec) * MS);
	}
}