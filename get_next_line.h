/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:48:05 by vboxuser          #+#    #+#             */
/*   Updated: 2025/01/26 10:44:13 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <sys/types.h>

char	*get_next_line(int fd);
char	*ft_resize(char **buffer, size_t *size);
size_t	ft_strchr(const char *buf, const char c, const size_t size);
char	*ft_take_line(char **buffer, size_t *size, size_t *len);

#endif