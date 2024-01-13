/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:00:37 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/13 21:15:04 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprintf(t_list *lst, char c)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		ft_printf("node: %i - pointer: %p - Content: ", i, tmp);
		if (c == 'i')
			ft_printf("%i - ", *(int *)(tmp->content));
		else if (c == 'c')
			ft_printf("%c - ", *(char *)(tmp->content));
		else if (c == 's')
			ft_printf("%s - ", *(char *)(tmp->content));
		ft_printf("Next Pointer: %p\n", tmp->next);
		tmp = tmp->next;
		i++;
	}
}
