/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:52:32 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/16 21:50:24 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*before;
	t_list	*tmp;

	first = NULL;
	while (lst)
	{
		tmp = (t_list *)malloc(1 * sizeof(t_list));
		if (!tmp)
		{
			if (first)
				ft_lstclear(&first, del);
			return (NULL);
		}
		tmp->next = NULL;
		tmp->content = f(lst->content);
		if (!first)
			first = tmp;
		else
			before->next = tmp;
		before = tmp;
		lst = lst->next;
	}
	return (first);
}
