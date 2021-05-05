# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taekang <taekang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 12:45:02 by ncolomer          #+#    #+#              #
#    Updated: 2021/03/27 14:15:35 by taekang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c \

OBJS		= $(SRCS:.c=.o)

CC		= arch -x86_64 gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
LIBS	= -L. -lft 
LIBFT	= libft.a

NAME	= pushSwap

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
		$(CC) ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

$(LIBFT):
		@$(MAKE) -C libft
		@mv libft/$(LIBFT) .
clean:
		@$(MAKE) -C libft clean
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME) $(LIBFT)

re:		fclean $(NAME)

.PHONY:		all clean fclean re
