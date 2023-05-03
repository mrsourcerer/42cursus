/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_math.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:08:16 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/03 06:15:38 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mid_element(t_list *a, int size)
{
	t_list	*l_tmp;
	t_list	*l_mid;
	int		i;

	l_mid = a;
	while (l_mid)
	{
		i = 0;
		l_tmp = a;
		while (l_tmp)
		{
			if (ft_content(l_tmp) < ft_content(l_mid))
				i++;
			l_tmp = l_tmp->next;
		}
		if (i == size / 2)
			return (ft_content(l_mid));
		l_mid = l_mid->next;
	}
	return (0);
}

int	ft_min_max_values(int *values, int len, int operation)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = values[0];
	max = values[0];
	while (i < len)
	{
		if (values[i] < min)
			min = values[i];
		if (values[i] > max)
			max = values[i];
		i++;
	}
	if (operation > 0)
		return (max);
	if (operation < 0)
		return (min);
	return (0);
}
