/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:49:11 by vboxuser          #+#    #+#             */
/*   Updated: 2025/01/26 10:40:42 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char		*buffer;
	static size_t	size;
	static size_t	len;
	ssize_t			bytes_read;

	bytes_read = 1;
	while ((!buffer || ft_strchr(buffer, '\n', len) == len) && bytes_read > 0)
	{
		if (!buffer || size - len < BUFFER_SIZE)
			ft_resize(&buffer, &size);
		bytes_read = read(fd, buffer + len, BUFFER_SIZE);
		if (bytes_read != -1)
			len += bytes_read;
	}
	if (bytes_read >= 0 && len > 0)
		return (ft_take_line(&buffer, &size, &len));
	free(buffer);
	buffer = NULL;
	size = 0;
	len = 0;
	return (NULL);
}
