# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taesan <taesan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by taekang           #+#    #+#              #
#    Updated: 2021/05/05 20:11:33 by taesan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = liblinked_list.a

SRCS =			ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstnew.c\
				ft_lstsize.c\
				ft_list_print.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -rf

AR = ar
ARFLAGS = rcs

$(NAME) : $(OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)
all: $(NAME)

clean: 	
	$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
