# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taesan <taesan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by taekang           #+#    #+#              #
#    Updated: 2020/12/30 02:22:37 by taesan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

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

$(NAME) : $(LIBFT) $(OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(LIBFT_DIR)/$(LIBFT) $(OBJS)

$(LIBFT) :
		$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean: clean_libft
		$(RM) $(RMFLAGS) $(OBJS) $(LIBFT_OBJS)

clean_libft:
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		$(RM) $(RMFLAGS) $(NAME) $(LIBFT_DIR)/$(LIBFT)

re:		fclean all

.PHONY: all clean fclean re
