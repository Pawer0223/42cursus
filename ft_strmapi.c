/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:31:28 by taekang           #+#    #+#             */
/*   Updated: 2020/10/15 19:47:46 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char test(unsigned int n, char c)
{
	return (c + 1);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	int				len;
	unsigned int	i;

	len = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * len)))
		return (0);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}

void	call(int argc, char *argv[])
{
	ft_strmapi(argv[1], test);
}


int main(int argc, char *argv[])
{

}
