/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekang <taekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:02:48 by taekang           #+#    #+#             */
/*   Updated: 2021/03/29 16:10:38 by taekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define IDENTIFIERS 9
# define NORTH 0
# define SOUTH 1
# define SPRITE 2
# define EAST 3
# define WEST 4
# define FLOOR 5
# define CEILING 6
# define RESOLUTION 7
# define MAP_LINE 8
# define WALL 1

# define MAX_X 800
# define MAX_Y 1280

# define MIN_X 320
# define MIN_Y 640

# define U_DIV 1
# define V_DIV 1
# define V_MOVE 0.0
#endif
