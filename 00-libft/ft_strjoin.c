/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:47:24 by mlazzare          #+#    #+#             */
/*   Updated: 2021/01/18 19:18:31 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		l;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
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
