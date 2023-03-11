/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 07:39:24 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/11 13:24:49 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **a, t_list **b, char c)
{
	t_list	*tmp;

	if (c == 'a' || c == 's')
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
	if (c == 'b' || c == 's')
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
	}
	ft_printf("s%c\n", c);
}

void	ft_rotate(t_list **a, t_list **b, char c)
{
	t_list	*tmp_first;
	t_list	*tmp_last;

	if (c == 'a' || c == 'r')
	{
		tmp_first = *a;
		tmp_last = ft_lstlast(*a);
		*a = (*a)->next;
		tmp_last->next = tmp_first;
		tmp_first->next = NULL;
	}
	if (c == 'b' || c == 'r')
	{
		tmp_first = *b;
		tmp_last = ft_lstlast(*b);
		*b = (*b)->next;
		tmp_last->next = tmp_first;
		tmp_first->next = NULL;
	}
	ft_printf("r%c\n", c);
}

void	ft_revrotate(t_list **a, t_list **b, char c)
{
	// implementar reverse rotate
}