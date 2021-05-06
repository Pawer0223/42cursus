/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:12:31 by taekang           #+#    #+#             */
/*   Updated: 2021/05/06 18:06:43 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "../libft/libft.h"
# include "../error.h"

# define Y 'Y'
# define N 'N'

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
	char			is_first;
	char			is_last;
}				t_list;

/*
	** create, delete
*/
t_list			*ft_lstnew(t_list **start, void *content);
void			ft_lstadd_front(t_list **start, t_list *new);
void			ft_lstadd_back(t_list **start, t_list *new);
void			ft_lstclear(t_list **start);
void			ft_lstdelone(t_list *list);

/*
	** counting...
*/
int				ft_lstsize(t_list **start);
t_list			*ft_lstlast(t_list **start);

/*
	** utils
*/ 
int				is_first(t_list *list);
int				is_last(t_list *list);
int				is_null(t_list **start);

/*
	** using for test..
*/
void			ft_list_print(t_list **start);

#endif
