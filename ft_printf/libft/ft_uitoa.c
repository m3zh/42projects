/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:07:35 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/31 22:17:50 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int nb)
{
	char	*a;
	int		l;

	l = ft_numlen(nb);
	a = (char *)malloc(sizeof(char) * (l + 1));
	if (!a)
		return (NULL);
	a[l--] = '\0';
	if (nb == 0)
		a[l] = 0 + '0';
	while (nb > 0)
	{
		a[l--] = nb % 10 + '0';
		nb /= 10;
	}
	return (a);
}
