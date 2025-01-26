/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:49:11 by vboxuser          #+#    #+#             */
/*   Updated: 2025/01/26 12:48:54 by alopez-v         ###   ########.fr       */
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
	char			*line;
	ssize_t			bytes_read;

	if (!buffer)
		bytes_read = ft_fetch(&buffer, &size, &len, fd);
	while (bytes_read > 0 && !ft_find_line(&buffer, &len, &line))
	{
		bytes_read = ft_fetch(&buffer, &size, &len, fd);
		if (bytes_read == -1)
		{
			ft_free(&buffer, &size, &len);
			return (NULL);
		}
	}
	if (bytes_read == 0)
		return (ft_take_buffer(&buffer, &size, &len));
	return (line);
}
