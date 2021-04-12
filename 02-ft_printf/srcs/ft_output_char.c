/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/04/07 18:58:38 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_output_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	ft_update_tab(tab, 1);
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, 0);
	tab->tl += write(1, &a, 1);
	if (tab->wdt && tab->dash)
		ft_left_cs(tab, 0);
}

void	ft_percentage(t_print *tab)
{
	if (tab->perc)
		tab->zero = 1;
	while (tab->zero && !tab->dash && --tab->wdt > 0)
		tab->tl += write(1, "0", 1);
	while (!tab->dash && --tab->wdt > 0)
		tab->tl += write(1, " ", 1);
	tab->tl += write(1, "%", 1);
	while (tab->dash && --tab->wdt > 0)
		tab->tl += write(1, " ", 1);
}

int	ft_space(t_print *tab, int pos)
{
	pos++;
	tab->sp = 1;
	return (pos);
}
