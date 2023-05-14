/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:25:49 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/14 07:23:56 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_mid(t_list **a, t_list **b)
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
