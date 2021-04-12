/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/04/09 16:53:18 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_write_zero_point(t_print *tab)
{
	if (tab->prc < 0)
		tab->tl += write(1, "0", 1);
	while (!tab->wdt && tab->prc-- > 0)
		tab->tl += write(1, "0", 1);
}

void	ft_write_zero(t_print *tab)
{
	tab->is_zero = 1;
	if ((tab->wdt && tab->zero) || tab->pnt)
	{
		ft_right_zero(tab);
		return ;
	}
	ft_update_tab(tab, 1);
	while (!tab->dash && --tab->wdt > 0)
		tab->tl += write(1, " ", 1);
	tab->tl += write(1, "0", 1);
	while (tab->dash && --tab->wdt > 0)
		tab->tl += write(1, " ", 1);
}

void	ft_output_int(t_print *tab)
{
	int		i;
	int		j;
	char	*num;
	int		len;

	i = 0;
	j = va_arg(tab->args, int);
	if (!j)
	{
		ft_write_zero(tab);
		return ;
	}
	if (j < 0)
		j = ft_check_sign(tab, j);
	num = ft_itoa(j);
	if (!num)
		return ;
	len = ft_strlen(num);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	while (j && num[i])
		tab->tl += write(1, &num[i++], 1);
	ft_left_idupx(tab);
	free(num);
}

void	ft_output_unsigned_int(t_print *tab)
{
	int				i;
	unsigned int	j;
	char			*num;
	int				len;

	i = 0;
	j = va_arg(tab->args, int);
	if (!j)
	{
		ft_write_zero(tab);
		return ;
	}
	num = ft_uitoa(j);
	if (!num)
		return ;
	len = ft_numlen(j);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	while (num[i])
		tab->tl += write(1, &num[i++], 1);
	ft_left_idupx(tab);
	free(num);
}
