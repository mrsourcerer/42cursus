/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:09:18 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/20 06:58:06 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_min(t_list **a, t_list **b)
{
	ft_printf("ft_sort_min: %i elements\n", ft_lstsize(*a));
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
		ft_swap(a, b, 'a');
	if (ft_sorted_int(*a, ft_lstsize(*a)))
		return (0);
	ft_revrotate(a, b, 'a');
	if (ft_sorted_int(*a, ft_lstsize(*a)))
		return (0);
	ft_swap(a, b, 'a');
	return (0);
}

int	ft_sort_min_four(t_list **a, t_list **b)
{
	int	i;

	ft_printf("ft_sort_min_four: %i elements\n", ft_lstsize(*a));
	i = 0;
	while (i++ < 2)
	{
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			ft_swap(a, b, 'a');
		ft_push(a, b, 'b');
	}
	if ((ft_content(*a) > ft_content((*a)->next)) \
		&& (ft_content(*b) < ft_content((*b)->next)))
		ft_swap(a, b, 's');
	if (ft_content(*a) > ft_content((*a)->next))
		ft_swap(a, b, 'a');
	if (ft_content(*b) < ft_content((*b)->next))
		ft_swap(a, b, 'b');
	ft_push(a, b, 'a');
	ft_sort_min(a, b);
	ft_push(a, b, 'a');
	if (ft_content(*a) > ft_content((*a)->next))
		ft_swap(a, b, 'a');
	return (0);
}

int	ft_sort_min_five(t_list **a, t_list **b)
{
	int	pos;

	pos = ft_min_pos(*a);
	ft_printf("pos: %i\n", pos);
	ft_push(a, b, 'b');
	ft_sort_min_four(a, b);
	return (0);
}
