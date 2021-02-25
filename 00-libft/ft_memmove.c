/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:31:16 by mlazzare          #+#    #+#             */
/*   Updated: 2020/11/14 11:31:18 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tmp;

	i = -1;
	tmp = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
		while (n-- > 0)
			((char *)dest)[n] = tmp[n];
	else
		while (++i < n)
			((char *)dest)[i] = tmp[i];
	return (dest);
}
