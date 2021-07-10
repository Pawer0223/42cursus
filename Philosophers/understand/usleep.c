#include "understand.h"

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