/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:46:12 by mlazzare          #+#    #+#             */
/*   Updated: 2021/04/09 16:49:08 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# define MAX_LONG	9223372036854775807

size_t	ft_strlen(const char *s);
int		ft_numlen(long n);
int		ft_numlen_base(unsigned long n, int base);
int		ft_putnbr_base(unsigned long n, char *base);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_putchar(char c);
int		ft_atoi(const char *nptr);
char	*ft_uitoa(unsigned int nb);
void	ft_putnbr(int nbr);
char	*ft_itoa(int n);
char	*ft_itoa_base(char *str, unsigned long n, int base, int c);

#endif
