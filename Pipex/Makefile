# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taesan <taesan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:51:22 by taesan            #+#    #+#              #
#    Updated: 2021/07/07 13:31:01 by taesan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

LIBFT_DIR		= ./libft
GNL_DIR			= ./gnl
COMMON_DIR		= ./common
BONUS_DIR		= ./bonus

CC		= arch -x86_64 gcc -g #-g is modify !
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

SRCS				=	$(wildcard *.c)
LIBFT_SRCS			=	$(wildcard $(LIBFT_DIR)/*.c)
GNL_SRCS			=	$(wildcard $(GNL_DIR)/*.c)
COMMON_SRCS			=	$(wildcard $(COMMON_DIR)/*.c)
BONUS_SRCS			=	$(wildcard $(BONUS_DIR)/*.c)

OBJS				=	$(SRCS:.c=.o)
LIBFT_OBJS			=	$(addprefix $(LIBFT_DIR)/, $(notdir $(LIBFT_SRCS:.c=.o)))
GNL_OBJS			=	$(addprefix $(GNL_DIR)/, $(notdir $(GNL_SRCS:.c=.o)))
COMMON_OBJS			=	$(addprefix $(COMMON_DIR)/, $(notdir $(COMMON_SRCS:.c=.o)))
BONUS_OBJS			=	$(addprefix $(BONUS_DIR)/, $(notdir $(BONUS_SRCS:.c=.o)))

ifdef BONUS
	OBJ_FILES = $(BONUS_OBJS) $(LIBFT_OBJS) $(GNL_OBJS) $(COMMON_OBJS)
else
	OBJ_FILES = $(OBJS) $(LIBFT_OBJS) $(GNL_OBJS) $(COMMON_OBJS)
endif

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
		$(CC) ${CFLAGS} -o ${NAME} $(OBJ_FILES)

bonus:
		make BONUS=1 all

clean:
		$(RM) $(OBJS) $(LIBFT_OBJS) $(GNL_OBJS) $(COMMON_OBJS) $(BONUS_OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

leak:
		leaks -atExit -- ./pipex

.PHONY:	all bonus clean fclean re leak
