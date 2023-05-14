/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:09:18 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/14 07:02:42 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_min(t_list **a, t_list **b)
{
	if (ft_content(*a) > ft_content((*a)->next) && \
		ft_content(*a) > ft_content(((*a)->next)->next))
		ft_rotate(a, b, 'a');
	if (ft_sorted_int(*a))
		return (0);
	if (ft_content(*a) > ft_content((*a)->next))
		ft_swap(a, b, 'a');
	if (ft_sorted_int(*a))
		return (0);
	ft_revrotate(a, b, 'a');
	if (ft_sorted_int(*a))
		return (0);
	ft_swap(a, b, 'a');
	return (77);
}

int	ft_sort_min_general(t_list **a, t_list **b)
{
	int	i;
	int	j;

	i = ft_lstsize(*a) - 3;
	j = i;
	while (i > 0)
	{
		ft_min_on_top(a, b);
		i--;
		if (ft_sorted_int(*a))
			i = 0;
		else
			ft_push(a, b, 'b');
	}
	ft_sort_min(a, b);
	while (j > 0)
	{
		ft_push(a, b, 'a');
		j--;
	}
	return (0);
}
