/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:21:03 by mlazzare          #+#    #+#             */
/*   Updated: 2020/11/23 22:21:13 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*mylist;

	if (!(mylist = (t_list *)malloc(sizeof(mylist))))
		return (NULL);
	mylist->content = content;
	mylist->next = NULL;
	return (mylist);
}
