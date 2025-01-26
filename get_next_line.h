/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:48:05 by vboxuser          #+#    #+#             */
/*   Updated: 2025/01/26 12:49:30 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <sys/types.h>

char	*get_next_line(int fd);
ssize_t	ft_fetch(char **buffer, size_t *size, size_t *len, int fd);
int		ft_find_line(char **buffer, size_t *len, char **line);
void	ft_free(char **buffer, size_t *size, size_t *len);
char	*ft_take_buffer(char **buffer, size_t *size, size_t *len);

#endif