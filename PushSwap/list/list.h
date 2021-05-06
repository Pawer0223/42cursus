/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:12:31 by taekang           #+#    #+#             */
/*   Updated: 2021/05/06 15:19:40 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "../libft/libft.h"

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

t_list			*ft_lstnew(t_list **start, void *content);
t_list			*ft_lstlast(t_list **start);
void			ft_lstadd_front(t_list **start, t_list *new);
int				is_first(t_list *list);
int				is_last(t_list *list);

int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));
void			ft_list_print(t_list **start);

#endif
