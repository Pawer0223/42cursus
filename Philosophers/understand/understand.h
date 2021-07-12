#ifndef UNDERSTAND_H
# define UNDERSTAND_H

#include <string.h>

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

#include "../philo/defines.h"

int		understand_thread(int n);
int		understand_detach(int n);
void	understand_usleep();
void	undestand_time();
void	undestand_mutex();



#endif