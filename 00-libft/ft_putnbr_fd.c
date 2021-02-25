/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:42:39 by mlazzare          #+#    #+#             */
/*   Updated: 2020/11/22 22:51:27 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		c;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	if (nb < 10)
		c = nb % 10 + '0';
	else if (nb >= 10)
	{
		c = nb % 10 + '0';
		ft_putnbr_fd(nb / 10, fd);
	}
	write(fd, &c, 1);
}
