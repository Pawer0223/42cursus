#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void    temp(void *i, void *j)
{
	printf("### [temp] ###\n");
	printf("i : [%p],		j : [%p]\n", &i , &j);
	int v1 = *(int *)i;
	int v2 = *(int *)&j;
	v1++;
	v2++;

	*(int *)i += 1;
	*(int *)(&j) += 1;

	return ;
}

int     main()
{
	int			i;
	int			j;
	void		*ptr_i;
	void		*ptr_j;

	i = 0;
	j = 0;
	ptr_i = &i;
	ptr_j = (void *)(long)j;
	printf("ptr_i : [%p],		ptr_j : [%p]\n", ptr_i , ptr_j);
	temp(ptr_i, ptr_j);
	printf("i : [%d],		j : [%d]\n", *(int *)ptr_i , *(int *)(&j));
	
	*(int *)ptr_i += 1;
	*(int *)(&j) += 1;

	temp(ptr_i, ptr_j);
	printf("i : [%d],		j : [%d]\n", *(int *)ptr_i , *(int *)(&j));


	return (1);
}