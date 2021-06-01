/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:12:31 by taekang           #+#    #+#             */
/*   Updated: 2021/06/01 17:05:47 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LIST_H
# define DOUBLE_LIST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct			s_list_db
{
	int					value;
	struct	s_list_db	*next;
	struct	s_list_db	*prev;
}						t_list_db;

t_list_db		*ft_lstnew(int num);
void			ft_lstadd_front(t_list_db **lst, t_list_db *new_c);
t_list_db		*ft_lstlast(t_list_db *lst);
void			ft_lstadd_back(t_list_db **lst, t_list_db *new_c);
void			ft_lstclear(t_list_db **lst);
void			ft_lstiter(t_list_db *lst, void (*f)(int));
t_list_db		*get_list(t_list_db **list, int idx);
t_list_db		*pop(t_list_db **list);

#endif
