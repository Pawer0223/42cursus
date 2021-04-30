#include <unistd.h>
#include <stdlib.h>

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*ptr;
	t_list	*ptr2;
	t_list	*next;

	ptr = *begin_list; // r8, [rdi]
	while (ptr)
	{
		ptr2 = *begin_list; // rdi, [rdi]
		while (ptr2->next)
		{
		    // ptr2->data = rdi, [rdi]
		    // ptr2->next->data
		      // rsi, [rdi + 8] (is ptr2->next)
		      // rdi, [rdi]
			if ((*cmp)(ptr2->data, ptr2->next->data) > 0)
			{
				next = ptr2->data; // r11, [rdi]
				ptr2->data = ptr2->next->data; // r10, [r9] -> [rdi], r10
				ptr2->next->data = next; // [r9], r11
			}
			ptr2 = ptr2->next; // loop: r9, [rdi + 8] , beacuse liine 23
		}
		ptr = ptr->next; // next
	}
}

void	c_ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*list;

	if (*begin_list)
	{
		list = ft_create_elem(data);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = ft_create_elem(data);
}

char	*c_ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i])
		dest[i] = 0;
	return (dest);
}
