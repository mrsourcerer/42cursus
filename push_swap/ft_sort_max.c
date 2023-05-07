/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:13:25 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/07 12:47:12 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_return(t_list **a, t_list **b, int j, int max)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize(*b);
	if (j == max)
		j = -1;
	while (i < len)
	{
		if (j == -1)
			ft_push(a, b, 'a');
		else if (((ft_content(*b) >> (j + 1)) & 1) == 0)
			ft_rotate(a, b, 'b');
		else
			ft_push(a, b, 'a');
		i++;
	}
}

static void	ft_push_radix(t_list **a, t_list **b, int j)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize(*a);
	while (i < len)
	{
		if (((ft_content(*a) >> j) & 1) == 0)
			ft_push(a, b, 'b');
		else
			ft_rotate(a, b, 'a');
		i++;
	}
}

static int	ft_bin_digits(int n)
{
	int	result;
	int	i;

	result = n;
	i = 0;
	while (result)
	{
		result = result / 2;
		i++;
	}
	return (i);
}

int	ft_sort_max(t_list **a, t_list **b)
{
	int	j;
	int	len;

	j = 0;
	len = ft_bin_digits(ft_lstsize(*a));
	while (j < len)
	{
		ft_push_radix(a, b, j);
		ft_return(a, b, j, len);
		j++;
		if (ft_sorted_int(*a) && ft_revsorted_int(*b))
		{
			ft_return(a, b, len, len);
			return (74);
		}
	}
	return (0);
}
