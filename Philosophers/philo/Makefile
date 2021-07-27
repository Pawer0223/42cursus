# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taesan <taesan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:51:22 by taesan            #+#    #+#              #
#    Updated: 2021/07/27 19:54:21 by taesan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

SRCS				=	init.c error.c time.c utils.c \
						main.c monitor.c philosopher.c

OBJS				=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) ${CFLAGS} -o ${NAME} $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re
