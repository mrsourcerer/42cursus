/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:05:00 by bde-mada          #+#    #+#             */
/*   Updated: 2022/12/12 16:57:00 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*iter(t_list *l, t_list *s, void *(*f)(void *))
{
	if (l)
	{
		s = ft_lstnew(f(l->content));
		if (!s)
			return (NULL);
		s->next = iter(l->next, s->next, f);
	}
	return (s);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;

	start = NULL;
	start = iter(lst, start, f);
	if (!start)
		ft_lstclear(&lst, del);
	return (start);
}
