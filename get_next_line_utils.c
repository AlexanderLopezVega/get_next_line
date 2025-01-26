/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:22:16 by vboxuser          #+#    #+#             */
/*   Updated: 2025/01/26 12:47:42 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int		ft_find_line(char **buffer, size_t *len, char **line)
{
	size_t	line_len;
	size_t	i;

	if (!buffer || !len)
		return (0);
	line_len = 0;
	while (line_len < *len && buffer[line_len] != '\n')
		++line_len;
	if (line_len == *len)
		return (0);
	*line = malloc(sizeof(char) * (line_len + 1));
	if (!*line)
		return (-1);
	i = 0;
	while (i < line_len)
	{
		(*line)[i] = (*buffer)[i];
		(*buffer)[i] = (*buffer)[line_len + i];
		++i;
	}
	while (line_len + i < *len)
	{
		(*buffer)[i] = (*buffer)[line_len + i];
		++i;
	}
	(*line)[line_len] = '\0';
	*len -= line_len;
	return (1);
}

ssize_t	ft_fetch(char **buffer, size_t *size, size_t *len, int fd)
{
	char	*new_buffer;
	size_t	i;
	ssize_t	bytes_read;

	if (!buffer || !size || !len)
		return (-1);
	if (!*buffer || *size - *len < BUFFER_SIZE)
	{
		new_buffer = malloc(sizeof(char) * (*size + BUFFER_SIZE));
		if (!new_buffer)
			return (0);
		i = 0;
		while (i < *len)
		{
			new_buffer[i] = (*buffer)[i];
			++i;
		}
		if (*buffer)
			free(*buffer);
		*buffer = new_buffer;
		*size += BUFFER_SIZE;
	}
	bytes_read = read(fd, *buffer + *len, BUFFER_SIZE);
	if (bytes_read == -1)
		return (-1);
	*len += bytes_read;
	return (bytes_read);
}

void	ft_free(char **buffer, size_t *size, size_t *len)
{
	if (buffer && *buffer)
		free(*buffer);
	*buffer = NULL;
	*size = 0;
	*len = 0;
}
