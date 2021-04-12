/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:02:19 by mlazzare          #+#    #+#             */
/*   Updated: 2021/04/06 08:55:52 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print	*ft_reset_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->sp = 0;
	return (tab);
}

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->sp = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		r;

	if (!format)
		return (0);
	r = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	i = -1;
	va_start(tab->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_eval_format(tab, format, i + 1);
		else
			r += write(1, &format[i], 1);
	}
	r += tab->tl;
	va_end(tab->args);
	free(tab);
	return (r);
}
