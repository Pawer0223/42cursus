# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taesan <taesan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:51:22 by taesan            #+#    #+#              #
#    Updated: 2021/05/23 20:17:12 by taesan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR		= ./libft

SRCS				=	$(wildcard *.c)
LIBFT_SRCS			=	$(wildcard $(LIBFT_DIR)/*.c)

OBJS				=	$(SRCS:.c=.o)
LIBFT_OBJS			=	$(addprefix $(LIBFT_DIR)/, $(notdir $(LIBFT_SRCS:.c=.o)))

CC		= arch -x86_64 gcc -g #-g is modify !
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT_OBJS)
		$(CC) ${CFLAGS} -o ${NAME} ${OBJS} $(LIBFT_OBJS)

clean:
		$(RM) $(OBJS) $(LIBFT_OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

leak: 
		leaks -atExit -- ./push_swap

.PHONY:	all clean fclean re checkleak
