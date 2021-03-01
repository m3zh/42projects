/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:22:44 by ebodart           #+#    #+#             */
/*   Updated: 2021/03/01 14:38:59 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **line)
{
	if (line)
	{
		free(*line);
		*line = NULL;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*r;
	size_t			i;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = (unsigned int)ft_strlen(s);
	if (s_len < start)
		len = 0;
	else if (s_len < start + len)
		len = s_len - start;
	if (!(r = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		r[i++] = s[start++];
	r[i] = '\0';
	return (r);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r;
	int		l;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!s1)
		return (s2);
	l = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	if (!(r = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	while (*s1)
		r[i++] = *s1++;
	while (*s2)
		r[i++] = *s2++;
	r[i] = '\0';
	return (r);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = ft_strlen(src);
	if (!(dup = (char *)malloc(sizeof(*src) * (len + 1))))
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
