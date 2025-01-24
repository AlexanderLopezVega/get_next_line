/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:54:06 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/24 19:58:36 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

ssize_t	ft_arrlst_popfront(t_arrlst *arrlst, void **buffer, const size_t n)
{
	size_t	buf_len;
	size_t	i;

	buf_len = n;
	if (buf_len > arrlst->len)
		buf_len = arrlst->len;
	*buffer = malloc(sizeof(char) * n);
	if (!*buffer)
		return (-1);
	i = 0;
	while (i < buf_len)
	{
		((unsigned char *)buffer)[i] = ((unsigned char *)arrlst->arr)[i];
		++i;
	}
	while (i < arrlst->len)
	{
		((unsigned char *)arrlst->arr)[i - buf_len] = ((unsigned char *)arrlst->arr)[i];
		((unsigned char *)arrlst->arr)[i] = '\0';
		++i;
	}
	return (buf_len);
}

int	ft_arrlst_pushback(t_arrlst *arrlst, const void *buf, const size_t n)
{
	size_t	i;
	
	while (n > arrlst->size - arrlst->len)
		if (ft_arrlst_resize(arrlst, arrlst->size + arrlst->increment))
			return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)arrlst->arr)[arrlst->len + i] = ((unsigned char *)buf)[i];
		++i;
	}
	arrlst->len += n;
	return (1);
}

int	ft_arrlst_resize(t_arrlst *arrlst, const size_t n)
{
	size_t	i;
	void	*new_buf;

	new_buf = malloc(sizeof(char) * n);
	if (!new_buf)
		return (0);
	i = 0;
	while (i < arrlst->len && i < n)
	{
		((unsigned char *)new_buf)[i] = ((unsigned char *)arrlst->arr)[i];
		++i;
	}
	while (i < n)
	{
		((unsigned char *)new_buf)[i] ='\0';
		++i;
	}
	free(arrlst->arr);
	arrlst->arr = new_buf;
	return (1);
}

void	ft_free_resources(t_arrlst **arrlst, char **read_buf)
{
	if (*arrlst)
	{
		if ((*arrlst)->arr)
		{
			free((*arrlst)->arr);
			(*arrlst)->arr = NULL;
		}
		free(*arrlst);
		*arrlst = NULL;
	}
	if (*read_buf)
	{
		free(*read_buf);
		*read_buf = NULL;
	}
}

char	*ft_strchr(const char *s, const char c)
{
	char	*iter;

	iter = (char *)s;
	while (*iter != '\0')
	{
		if (*((unsigned char *)iter) == (unsigned char)c)
			return (iter);
		++iter;
	}
	if ((unsigned char)c == '\0')
		return (iter);
	return (NULL);
}
