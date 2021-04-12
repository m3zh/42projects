/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:16:38 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/31 22:18:53 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

int	ft_numlen_base(unsigned long n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
	{
		i += 1;
		return (i);
	}
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}
