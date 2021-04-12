/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dash_and_star.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/04/07 19:11:41 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_eval_zero(t_print *tab, const char *format, int pos)
{
	int	i;

	i = 0;
	pos++;
	tab->zero = 1;
	while (format[pos] == '0')
		pos++;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_numlen(i);
	}
	tab->wdt = i;
	return (pos);
}

int	ft_eval_precision(t_print *tab, const char *format, int pos)
{
	int	i;

	i = 0;
	pos++;
	tab->pnt = 1;
	if (ft_isalpha(format[pos]) || format[pos] == '%')
		ft_check_precision(tab);
	while (format[pos] == '0' || ft_check_flag(format[pos]))
	{
		pos++;
		ft_check_precision(tab);
	}
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_numlen(i);
	}
	tab->prc = i;
	if (format[pos] == '*')
		pos = ft_eval_star(tab, format, pos);
	while (format[pos] == '*')
		pos++;
	return (pos);
}

int	ft_eval_dash(t_print *tab, const char *format, int pos)
{
	pos++;
	if (tab->dash == 1)
	{
		while (format[pos] == '-' || format[pos] == '0')
			pos++;
		return (pos);
	}
	tab->dash = 1;
	tab->zero = 0;
	while (format[pos] == '-' || format[pos] == '0')
		pos++;
	pos = ft_eval_width(tab, format, pos);
	return (pos);
}

int	ft_eval_star(t_print *tab, const char *format, int pos)
{
	pos++;
	if (!tab->pnt)
	{
		tab->wdt = va_arg(tab->args, int);
		ft_check_width(tab);
	}
	else
	{
		tab->prc = va_arg(tab->args, int);
		ft_check_precision(tab);
	}
	if (format[pos] == '.')
		pos = ft_eval_precision(tab, format, pos);
	if (format[pos] == '*')
		pos = ft_eval_star(tab, format, pos);
	while (format[pos] == '*')
		pos++;
	return (pos);
}

int	ft_eval_width(t_print *tab, const char *format, int pos)
{
	int	i;

	i = 0;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_numlen(i);
	}
	tab->wdt = i;
	if (format[pos] == '.')
		pos = ft_eval_precision(tab, format, pos);
	return (pos);
}
