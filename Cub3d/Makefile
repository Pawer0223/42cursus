# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taekang <taekang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 12:45:02 by ncolomer          #+#    #+#              #
#    Updated: 2021/03/26 17:41:54 by taekang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.c save_bmp.c utils.c \
					game_info_init.c manage_map.c cub3d.c \
					parse_file.c parse_check.c parse_color.c parse_utils.c map_valid_check.c \
					fill_sprite.c fill_data.c fill_floor.c \
					ray.c key_press.c get_next_line.c list_func.c debug_print.c\

OBJS			= $(SRCS:.c=.o)

CC				= arch -x86_64 gcc
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX				= libmlx.dylib

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

clean:
				@$(MAKE) -C mlx clean
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re