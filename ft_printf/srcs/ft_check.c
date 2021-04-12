/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/04/09 16:29:40 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_check_precision(t_print *tab)
{
	if (tab->prc == 0 && tab->zero == 1)
	{
		tab->zero = 0;
		tab->perc = 1;
	}
	if (tab->prc < 0)
	{
		tab->prc = 0;
		tab->pnt = 0;
	}
}

void	ft_check_width(t_print *tab)
{
	if (tab->wdt < 0)
	{
		tab->wdt *= -1;
		tab->dash = 1;
		tab->zero = 0;
	}
}

int	ft_check_sign(t_print *tab, int j)
{
	tab->sign = 1;
	tab->sp = 0;
	return (j * -1);
}

int	ft_check_flag(char c)
{
	if (c == '-' || c == '.')
		return (1);
	return (0);
}
