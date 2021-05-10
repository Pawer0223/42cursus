/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:13:58 by taesan            #+#    #+#             */
/*   Updated: 2021/05/10 18:43:43 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	delete_content(void *content)
{
	free(content);
}

int		error_occur(t_list **list)
{
	ft_lstclear(list, delete_content);
	ft_putendl_fd(ERROR, 1);
	return (0);
}