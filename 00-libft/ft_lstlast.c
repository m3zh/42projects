/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:24:30 by mlazzare          #+#    #+#             */
/*   Updated: 2021/01/13 20:49:18 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*end;

	if (!lst)
		return (NULL);
	if (!(lst->next))
		return (lst);
	end = lst->next;
	while (end->next)
		end = end->next;
	return (end);
}
