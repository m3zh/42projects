/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/04/08 14:25:28 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_right_idupx(t_print *tab)
{
	if (tab->sp)
		tab->tl += write(1, " ", 1);
	if (tab->sign && (tab->zero || tab->dash || (!tab->wdt && !tab->prc)))
	{
		tab->tl += write(1, "-", 1);
		tab->sign = 0;
	}
	if (!tab->dash)
	{
		while (!tab->zero && --tab->wdt > -1)
			tab->tl += write(1, " ", 1);
		while (tab->zero && --tab->wdt > -1)
			tab->tl += write(1, "0", 1);
		if (tab->sign)
			tab->tl += write (1, "-", 1);
	}
	while (--tab->prc > -1)
		tab->tl += write(1, "0", 1);
}

void	ft_left_idupx(t_print *tab)
{
	if (tab->dash)
	{
		while (tab->dash && tab->zero && --tab->prc > -1)
			tab->tl += write(1, "0", 1);
		while (tab->dash && --tab->wdt > -1)
			tab->tl += write(1, " ", 1);
	}
}

void	ft_right_cs(t_print *tab, int len)
{
	while (tab->zero && tab->wdt-- > len)
		tab->tl += write(1, "0", 1);
	if (!tab->zero && tab->prc && tab->prc < len)
		while (tab->wdt-- > tab->prc)
			tab->tl += write(1, " ", 1);
	else
		while (!tab->zero && tab->wdt-- > len)
			tab->tl += write(1, " ", 1);
}

void	ft_left_cs(t_print *tab, int len)
{
	while (tab->zero && tab->wdt-- > len)
		tab->tl += write(1, "0", 1);
	while (!tab->zero && tab->wdt-- > len)
		tab->tl += write(1, " ", 1);
}

void	ft_right_zero(t_print *tab)
{
	if (tab->wdt && (tab->pnt || tab->zero))
	{
		if (!tab->prc)
		{
			while (tab->zero && tab->wdt-- > 0)
				tab->tl += write(1, "0", 1);
			while (!tab->zero && tab->wdt-- > 0)
				tab->tl += write(1, " ", 1);
		}
		else
		{
			tab->wdt -= tab->prc;
			while (tab->dash && tab->prc-- > 0)
				tab->tl += write(1, "0", 1);
			while (tab->wdt-- > 0)
				tab->tl += write(1, " ", 1);
			while (!tab->dash && tab->prc-- > 0)
				tab->tl += write(1, "0", 1);
		}
	}
	else if (tab->pnt)
		ft_write_zero_point(tab);
}
