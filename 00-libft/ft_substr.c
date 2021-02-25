/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:57:46 by mlazzare          #+#    #+#             */
/*   Updated: 2021/01/20 09:03:24 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
