/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:09:18 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/05 12:47:19 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int **a, int **b, char c)
{
	int	tmp;

	if (c == 'a' || c == 's')
	{
		tmp = (*a)[0];
		(*a)[0] = (*a)[1];
		(*a)[1] = tmp;
	}
	if (c == 'b' || c == 's')
	{
		tmp = (*b)[0];
		(*b)[0] = (*b)[1];
		(*b)[1] = tmp;
	}
	ft_printf("s%c\n", c);
}

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

int	ft_sort_min(int *a, int *b, int len)
{
	int	i;
	int	ab_len[2];

	ab_len[0] = len - 1;
	ab_len[1] = 0;
	while (1)
	{
		i = 0;
		while (i < len - 1)
		{

		}
		if (ft_sorted_int(a, len))
			return (0);
	}
}
