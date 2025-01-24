/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:34:08 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/24 19:59:00 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 256
#endif
#define INIT_SIZE 1024
#define SIZE_INCR 1024

char	*get_next_line(int fd)
{
	static t_arrlst *pers_buf;
	char 			*read_buf;
	ssize_t 		bytes_read;

	read_buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (read_buf)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read != -1)
		{
			while (bytes_read >= BUFFER_SIZE && !ft_strchr(read_buf, '\n'))
			{
				if (!ft_arrlst_pushback(pers_buf, read_buf, (size_t)bytes_read))
				{
					ft_free_resources(&pers_buf, &read_buf);
					return (NULL);
				}
				bytes_read = read(fd, read_buf, BUFFER_SIZE);
			}
			if (bytes_read != -1 && ft_arrlst_pushback(pers_buf, read_buf, (size_t)bytes_read))
			{
				free(read_buf);
				if (ft_arrlst_popfront(pers_buf, (void *)&read_buf, pers_buf->len + bytes_read))
					return (read_buf);
			}
		}
	}
	ft_free_resources(&pers_buf, &read_buf);
	return (NULL);
}