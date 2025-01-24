/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:14:17 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/24 20:27:33 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>

typedef struct s_arrlst
{
	void	*arr;
	size_t	increment;
	size_t	size;
	size_t	len;
}			t_arrlst;

ssize_t		ft_arrlst_popfront(t_arrlst *arrlst, void **buffer, const size_t n);
int			ft_arrlst_pushback(t_arrlst *arrlst, const void *buf,
				const size_t n);
int			ft_arrlst_resize(t_arrlst *arrlst, const size_t n);
void		ft_free_resources(t_arrlst **arrlst, char **read_buf);
char		*get_next_line(int fd);
char		*ft_strchr(const char *s, const char c);

#endif