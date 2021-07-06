/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taesan <taesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:19:05 by taesan            #+#    #+#             */
/*   Updated: 2021/01/05 18:14:10 by taesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*content_null(char *buf)
{
	char	*new_content;

	new_content = ft_strdup(buf);
	if (!new_content)
		return (0);
	return (new_content);
}

char	*check_first(int fd, char **line)
{
	char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (0);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	return (buf);
}
