/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:09:18 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/13 22:33:32 by danlopez         ###   ########.fr       */
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
	t_list	*last;

	ft_printf("ft_sort_min: %i elementos\n", ft_lstsize(*a));
	last = ft_lstlast(*a);
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

int	ft_sort_mid(t_list **a, t_list **b)
{
	ft_swap(a, b, 'a');
	return (0);
}
