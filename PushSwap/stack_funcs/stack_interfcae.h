/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_interfcae.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:09:58 by taesan            #+#    #+#             */
/*   Updated: 2021/05/22 16:49:40 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_INTERFACE_H
# define STACK_INTERFACE_H

# include "stack_funcs.h"

void	push(t_stacks *stacks, char name);
void	swap(t_stacks *stacks, char name);



# endif