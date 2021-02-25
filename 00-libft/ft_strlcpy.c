/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 08:55:03 by mlazzare          #+#    #+#             */
/*   Updated: 2021/01/19 22:40:53 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = -1;
	j = 0;
	if (!src)
		return (0);
	while (src[j])
		j++;
	if (!size)
		return (j);
	while (src[++i] && i < (size - 1))
		dst[i] = src[i];
	dst[i] = '\0';
	return (j);
}
