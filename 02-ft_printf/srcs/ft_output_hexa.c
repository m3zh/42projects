/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_hexa_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/04/07 16:23:57 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_output_hexa_int(t_print *tab, int c)
{
	unsigned int	j;
	int				len;
	char			*num;

	j = va_arg(tab->args, unsigned int);
	if (!j)
	{
		ft_write_zero(tab);
		return ;
	}
	len = ft_numlen_base(j, 16);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return ;
	num = ft_itoa_base(num, j, 16, c);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	while (num && len-- > 0)
		tab->tl += write(1, &num[len], 1);
	ft_left_idupx(tab);
	free(num);
}

void	ft_output_pointer(t_print *tab)
{
	unsigned long	j;
	int				l;

	l = 2;
	j = (unsigned long)va_arg(tab->args, void *);
	if (!j && tab->pnt && tab->prc > 0)
	{
		ft_write_null_p(tab);
		return ;
	}
	if (!(!j && tab->pnt))
		l += ft_numlen_base(j, 16);
	if (!tab->prc || tab->wdt > tab->prc)
	{
		ft_update_tab(tab, l);
		ft_right_idupx(tab);
	}
	else
		tab->prc = tab->prc + 2 - l;
	tab->tl += write(1, "0x", 2);
	while (tab->prc-- > 0)
		tab->tl += write(1, "0", 1);
	if (!(!j && tab->pnt))
		tab->tl += ft_putnbr_base(j, "0123456789abcdef");
	ft_left_idupx(tab);
}

void	ft_write_null_p(t_print *tab)
{
	if (tab->wdt > tab->prc)
	{
		while (tab->wdt-- > (tab->prc + 2))
			tab->tl += write(1, " ", 1);
	}
	tab->tl += write(1, "0x", 2);
	while (tab->prc-- > 0)
		tab->tl += write(1, "0", 1);
}
