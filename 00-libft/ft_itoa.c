/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:07:35 by mlazzare          #+#    #+#             */
/*   Updated: 2021/01/08 12:44:10 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count += 1;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*a;
	int		l;
	long	nb;

	nb = n;
	l = n_len(nb);
	if (!(a = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	a[l--] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		a[0] = '-';
	}
	if (nb == 0)
	{
		a[l] = 0 + '0';
	}
	while (nb > 0)
	{
		a[l--] = nb % 10 + '0';
		nb /= 10;
	}
	return (a);
}
