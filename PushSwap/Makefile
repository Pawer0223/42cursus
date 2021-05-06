# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taesan <taesan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:51:22 by taesan            #+#    #+#              #
#    Updated: 2021/05/06 17:32:20 by taesan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR	= ./libft
LIST_DIR	= ./list

SRCS		=	$(wildcard *.c)
LIBFT_SRCS	=	$(wildcard $(LIBFT_DIR)/*.c)
LIST_SRCS	=	$(wildcard $(LIST_DIR)/*.c)

OBJS		=	$(SRCS:.c=.o)
LIBFT_OBJS	=	$(addprefix $(LIBFT_DIR)/, $(notdir $(LIBFT_SRCS:.c=.o)))
LIST_OBJS	=	$(addprefix $(LIST_DIR)/, $(notdir $(LIST_SRCS:.c=.o)))

CC		= arch -x86_64 gcc -g
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

NAME	= pushSwap

all:		$(NAME)

$(NAME):	$(LIBFT) $(LIST) $(OBJS) $(LIBFT_OBJS) $(LIST_OBJS)
		$(CC) ${CFLAGS} -o ${NAME} ${OBJS} $(LIBFT_OBJS) $(LIST_OBJS)

clean:
		$(RM) $(OBJS) $(LIBFT_OBJS) $(LIST_OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re
