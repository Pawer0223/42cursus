# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taesan <taesan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by taekang           #+#    #+#              #
#    Updated: 2020/12/31 15:58:32 by taesan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = sources
LIBFT_DIR = $(SRC_DIR)/libft

SRCS =	$(addprefix $(SRC_DIR)/, \
	test_print.c\
	ft_set_width_pre.c\
	ft_check.c\
	ft_global.c\
	ft_manage_num.c\
	ft_math.c\
	ft_printf.c\
	ft_ascii_write.c\
	ft_set_com.c\
	ft_set_di.c\
	ft_set_f.c\
	ft_set_p.c\
	ft_set_str.c\
	ft_set_u.c\
	ft_set_x.c\
	ft_set_caller.c\
	ft_set_input_filter.c\
	ft_format_write.c\
	ft_set_caller2.c\
)

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -rf

AR = ar
ARFLAGS = rcs

$(NAME) : $(OBJS) libft
		cp $(LIBFT_DIR)/libft.a $(NAME)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)

libft :
		$(MAKE) -C $(LIBFT_DIR)

all:	$(NAME)

clean:
		$(RM) $(RMFLAGS) $(OBJS) $(LIBFT_OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
		$(RM) $(RMFLAGS) $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

bonus:	$(NAME)

.PHONY:	all clean fclean re libft bonus
