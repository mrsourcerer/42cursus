/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:09:18 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/15 07:31:27 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	ft_push(int **a, int **b, char c, int *ab_len[2])
{
	int	i;

	if (c == 'b')
	{
		ab_len[0]--;
		ab_len[1]++;
		i = 0;
		while (++i < *(ab_len[1]))
			(*b)[i + 1] = (*b)[i];
		(*b)[0] = (*a)[0];
		i = 0;
		while (++i < *(ab_len[0]))
			(*a)[i] = (*a)[i + 1];
	}
	if (c == 'a')
	{
		ab_len[1]--;
		ab_len[0]++;
		i = 0;
		while (++i < *(ab_len[1]))
			(*a)[i + 1] = (*a)[i];
		(*a)[0] = (*b)[0];
		i = 0;
		while (++i < *(ab_len[0]))
			(*b)[i] = (*b)[i + 1];
	}
}
*/
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

int	ft_sort_min_five(t_list **a, t_list **b)
{
	int	i;

	ft_printf("ft_sort_min_five: %i elements\n", ft_lstsize(*a));
	i = 0;
	while (i++ < 2)
	{
		if (*(int *) (*a)->content > *(int *) (*a)->next->content)
			ft_swap(a, b, 'a');
		ft_push(a, b, 'b');
	}
	if (ft_content(*a) > ft_content((*a)->next) && ft_content(*b) > ft_content((*b)->next)) //error
		ft_swap(a, b, 's');

	return (0);
}
