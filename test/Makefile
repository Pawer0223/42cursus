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

SRCS		=	main.c save_bmp.c utils.c \
				game_info_init.c manage_map.c cub3d.c \
				parse_file.c parse_check.c parse_color.c parse_utils.c map_valid_check.c \
				fill_sprite.c fill_data.c fill_floor.c \
				ray.c key_press.c get_next_line.c list_func.c debug_print.c\

OBJS		= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
LIBS	= -L. -lmlx -L. -lft -framework OpenGL -framework AppKit
MLX		= libmlx.a
LIBFT	= libft.a

NAME	= cub3D

all:		$(NAME)

$(NAME):	$(MLX) $(LIBFT) $(OBJS)
			$(CC) ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

$(MLX):
			@$(MAKE) -C mlx
			@mv mlx/$(MLX) .

$(LIBFT):
			@$(MAKE) -C libft
			@mv libft/$(LIBFT) .

clean:
			@$(MAKE) -C mlx clean
			@$(MAKE) -C libft clean
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) $(MLX) $(LIBFT)

re:		fclean $(NAME)

.PHONY:		all clean fclean re
