/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:26:09 by mlazzare          #+#    #+#             */
/*   Updated: 2021/01/13 20:56:44 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst && (*lst))
	{
		ft_lstclear(&(*lst)->next, del);
		(*del)((*lst)->content);
		free((*lst));
		(*lst) = NULL;
	}
}
