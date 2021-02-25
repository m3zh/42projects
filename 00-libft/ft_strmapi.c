/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:03:12 by mlazzare          #+#    #+#             */
/*   Updated: 2021/01/18 19:48:16 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*a;
	size_t	i;

	i = -1;
	if (!f || !s || !(a = ft_strdup(s)))
		return (NULL);
	while (a[++i])
		a[i] = (*f)(i, s[i]);
	a[i] = '\0';
	return (a);
}
