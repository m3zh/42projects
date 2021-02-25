/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:31:10 by mlazzare          #+#    #+#             */
/*   Updated: 2021/01/18 19:17:30 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		k;
	int		len;
	char	*r;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	k = 0;
	len = (int)ft_strlen(s1);
	while (s1[i] && is_set(s1[i], set))
		i++;
	while (len > i && is_set(s1[len - 1], set))
		len--;
	if (!(r = (char *)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	while (i < len)
		r[k++] = s1[i++];
	r[k] = '\0';
	return (r);
}
