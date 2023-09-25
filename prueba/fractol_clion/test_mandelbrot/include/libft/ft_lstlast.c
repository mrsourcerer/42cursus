/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 06:54:23 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/11 13:09:53 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstbeforelast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}
