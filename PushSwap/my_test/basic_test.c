#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARG "ARG"
int size;

char			*test_error()
{
	printf("malloc error !\n");
	return (0);
}

void		permutation(int seq, char *visited, char *pos)
{
	if (seq == size)
	{
		setenv(ARG, pos, 1);
		// system("echo $ARG");
		system("./test.sh");
		//print_data(pos);
		return ;
	}
	for (int i = 0; i < size; i++)
	{
		if (!visited[i])
		{
			pos[seq * 2] = i + 1 + '0';
			pos[seq * 2 + 1] = ' ';
			visited[i] = 1;
			permutation(seq + 1, visited, pos);
			visited[i] = 0;
		}
	}
}

char		*make_ptr()
{
	char	*temp;
	int		len;

	len = size * 2 + 1;
	if (!(temp = (char *)malloc(sizeof(char) * len)))
		return (test_error());
	for (int i = 0; i <= len; i++)
		temp[i] = 0;
	return (temp);
}

int			main(int argc, char *argv[])
{
	char	*visited;
	char	*pos;
	int		max;

	max = 0;
	if (argc != 2)
	{
		printf("please call a.out [3 ~ 9]\n");
		return (0);
	}
	else
		max = atoi(argv[1]);
	if (max < 3 && max > 10)
	{
		printf("please call a.out [3 ~ 9]\n");
		return (0);
	}
	size = max;
	if (!(visited = make_ptr()))
		return (0);
	if (!(pos = make_ptr()))
		return (0);
	permutation(0, visited, pos);
	free(visited);
	free(pos);
	return (1);
}