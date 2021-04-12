/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 11:30:05 by mlazzare          #+#    #+#             */
/*   Updated: 2021/04/07 15:47:33 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_print
{
	va_list		args;
	int			wdt;
	int			prc;
	int			zero;
	int			pnt;
	int			dash;
	int			tl;
	int			sign;
	int			is_zero;
	int			perc;
	int			sp;
}				t_print;

int		ft_printf(const char *format, ...);
int		ft_eval_width(t_print *tab, const char *format, int pos);
int		ft_eval_precision(t_print *tab, const char *format, int pos);
int		ft_eval_format(t_print *tab, const char *format, int pos);
int		ft_eval_variable(t_print *tab, const char *format, int pos);
int		ft_eval_dash(t_print *tab, const char *format, int pos);
int		ft_eval_zero(t_print *tab, const char *format, int pos);
int		ft_eval_star(t_print *tab, const char *format, int pos);
void	ft_output_char(t_print *tab);
void	ft_output_string(t_print *tab);
void	ft_output_int(t_print *tab);
void	ft_output_unsigned_int(t_print *tab);
void	ft_output_pointer(t_print *tab);
void	ft_output_hexa_int(t_print *tab, int c);
void	ft_right_idupx(t_print *tab);
void	ft_left_idupx(t_print *tab);
void	ft_right_zero(t_print *tab);
void	ft_right_cs(t_print *tab, int len);
void	ft_left_cs(t_print *tab, int len);
void	ft_update_tab(t_print *tab, int len);
int		ft_update_tab_string(char *s, t_print *tab, int len);
void	ft_write_point(t_print *tab);
void	ft_write_zero(t_print *tab);
void	ft_write_zero_point(t_print *tab);
void	ft_write_null_p(t_print *tab);
void	ft_percentage(t_print *tab);
int		ft_space(t_print *tab, int pos);
void	ft_check_width(t_print *tab);
void	ft_check_precision(t_print *tab);
int		ft_check_sign(t_print *tab, int j);
int		ft_check_flag(char c);
t_print	*ft_initialise_tab(t_print *tab);
t_print	*ft_reset_tab(t_print *tab);

#endif
