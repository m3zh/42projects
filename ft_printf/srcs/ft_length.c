/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/31 20:55:51 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_update_tab_string(char *s, t_print *tab, int len)
{
	if (s)
		len = ft_strlen(s);
	if (tab->prc > 0 && len > tab->prc)
		len = tab->prc;
	return (len);
}

void	ft_update_tab(t_print *tab, int len)
{
	if (tab->sign)
	{
		if (tab->wdt)
			tab->wdt -= 1;
	}
	if (tab->prc > 0)
		tab->zero = 0;
	if (tab->wdt && tab->wdt >= tab->prc)
	{
		if (tab->prc > len)
			tab->prc -= len;
		else
			tab->prc = 0;
		if (!tab->is_zero)
			tab->wdt = tab->wdt - tab->prc - len;
	}
	else if (tab->prc > tab->wdt)
	{
		tab->wdt = 0;
		tab->prc -= len;
	}
}
