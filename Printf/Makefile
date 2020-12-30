# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taesan <taesan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by taekang           #+#    #+#              #
#    Updated: 2020/12/30 23:39:06 by taesan           ###   ########.fr        #
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

LIBFT_SRCS =	$(addprefix $(LIBFT_DIR)/, \
				ft_atoi.c\
	   			ft_bzero.c\
	   		 	ft_calloc.c\
	   		 	ft_isalnum.c\
	   		 	ft_isalpha.c\
	   		 	ft_isascii.c\
	   		 	ft_isdigit.c\
	   		 	ft_isprint.c\
	   		 	ft_itoa.c\
	   		 	ft_memccpy.c\
	   		 	ft_memchr.c\
	   		 	ft_memcmp.c\
	   		 	ft_memcpy.c\
	   		 	ft_memmove.c\
	   		 	ft_memset.c\
	   		 	ft_putchar_fd.c\
	   		 	ft_putendl_fd.c\
	   		 	ft_putnbr_fd.c\
	   		 	ft_putstr_fd.c\
	   		 	ft_split.c\
	   		 	ft_strchr.c\
	   		 	ft_strdup.c\
	   		 	ft_strjoin.c\
	   		 	ft_strlcat.c\
	   		 	ft_strlcpy.c\
	   		 	ft_strlen.c\
	   		 	ft_strmapi.c\
	   		 	ft_strncmp.c\
	   		 	ft_strnstr.c\
	   		 	ft_strrchr.c\
	   		 	ft_strtrim.c\
	   		 	ft_substr.c\
	   		 	ft_tolower.c\
	   		 	ft_toupper.c\
				ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c\
)

OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -rf

AR = ar
ARFLAGS = rcs

$(NAME) : $(OBJS) $(LIBFT_OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(LIBFT_OBJS)

all:	$(NAME)

clean:
		$(RM) $(RMFLAGS) $(OBJS) $(LIBFT_OBJS)

fclean: clean
		$(RM) $(RMFLAGS) $(NAME)

re:		fclean all

bonus:	$(NAME)

.PHONY:	all clean fclean re libft bonus
