# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taesan <taesan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:51:22 by taesan            #+#    #+#              #
#    Updated: 2021/07/10 13:37:48 by taesan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= understand

CC		= arch -x86_64 gcc -g #-g is modify !
RM		= rm -f
#CFLAGS	= -Wall -Wextra -Werror

SRCS				=	$(wildcard *.c)

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
