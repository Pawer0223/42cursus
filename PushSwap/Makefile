# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taesan <taesan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:51:22 by taesan            #+#    #+#              #
#    Updated: 2021/06/02 18:41:34 by taesan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIBFT_DIR		= ./libft
LIST_DIR		= ./doubly_linked_list

SRCS				=	$(wildcard *.c)
LIBFT_SRCS			=	$(wildcard $(LIBFT_DIR)/*.c)
LIST_SRCS			=	$(wildcard $(LIST_DIR)/*.c)

OBJS				=	$(SRCS:.c=.o)
LIBFT_OBJS			=	$(addprefix $(LIBFT_DIR)/, $(notdir $(LIBFT_SRCS:.c=.o)))
LIST_OBJS			=	$(addprefix $(LIST_DIR)/, $(notdir $(LIST_SRCS:.c=.o)))

CC		= arch -x86_64 gcc -g #-g is modify !
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT_OBJS) $(LIST_OBJS)
		$(CC) ${CFLAGS} -o ${NAME} ${OBJS} $(LIBFT_OBJS) $(LIST_OBJS)

clean:
		$(RM) $(OBJS) $(LIBFT_OBJS) $(LIST_OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

leak:
		leaks -atExit -- ./push_swap

.PHONY:	all clean fclean re leak
