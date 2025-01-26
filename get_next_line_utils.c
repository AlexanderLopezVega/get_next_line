/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:22:16 by vboxuser          #+#    #+#             */
/*   Updated: 2025/01/26 10:53:57 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static void	ft_move_front(char *buffer, const size_t len, const size_t offset)
{
	size_t	i;

	i = 0;
	while (offset + i < len)
	{
		buffer[i] = buffer[offset + i];
		++i;
	}
}

char	*ft_resize(char **buffer, size_t *size)
{
	char	*new_buffer;
	size_t	i;

	new_buffer = malloc(sizeof(char) * (*size + BUFFER_SIZE));
	if (!new_buffer)
	{
		if (*buffer)
			free(buffer);
		buffer = NULL;
		*size = 0;
		return (NULL);
	}
	i = 0;
	while (i < *size)
	{
		new_buffer[i] = (*buffer)[i];
		++i;
	}
	if (!*buffer)
		free(*buffer);
	*buffer = new_buffer;
	*size += BUFFER_SIZE;
	return (new_buffer);
}

size_t	ft_strchr(const char *buf, const char c, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (buf[i] == c)
			return (i);
		++i;
	}
	return (i);
}

char	*ft_take_line(char **buffer, size_t *size, size_t *len)
{
	size_t	line_len;
	size_t	i;
	char	*line;

	line_len = ft_strchr(*buffer, '\n', *len);
	if (line_len < *len && (*buffer)[line_len] == '\n')
		++line_len;
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
	{
		free(*buffer);
		*buffer = 0;
		*size = 0;
		*len = 0;
	}
	i = 0;
	while (i < line_len)
	{
		line[i] = (*buffer)[i];
		++i;
	}
	line[line_len] = '\0';
	ft_move_front(*buffer, *len, i);
	*len -= line_len;
	return (line);
}
