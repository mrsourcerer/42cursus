/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:09:43 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/24 07:26:54 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_int(t_list *a)
{
	int	i;
	int	len;

	len = ft_lstsize(a);
	if (len < 2)
		return (1);
	i = 0;
	while (i < len - 1)
	{
		if (ft_content(a) > ft_content(a->next))
			return (0);
		i++;
		a = a->next;
	}
	return (1);
}

int	ft_revsorted_int(t_list *a)
{
	int	i;
	int	len;

	len = ft_lstsize(a);
	if (len < 2)
		return (1);
	i = 0;
	while (i < len - 1)
	{
		if (ft_content(a) < ft_content(a->next))
			return (0);
		i++;
		a = a->next;
	}
	return (1);
}

int	ft_duplicated(int *a, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (a[i] == a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_min_pos(t_list *a)
{
	int	min;
	int	min_pos;
	int	i;

	min_pos = 1;
	i = 1;
	min = ft_content(a);
	while (a)
	{
		if (ft_content(a) < min)
		{
			min = ft_content(a);
			min_pos = i;
		}
		i++;
		a = a->next;
	}
	return (min_pos);
}

int	ft_min_on_top(t_list **a, t_list **b)
{
	int	pos;
	int	rotate;
	int	i;

	pos = ft_min_pos(*a);
	rotate = 1;
	if (pos * 10 / ft_lstsize(*a) > 5)
	{
		i = ft_lstsize(*a) - pos + 1;
		rotate = 0;
	}
	else
		i = pos - 1;
	while (i > 0)
	{
		if (rotate)
			ft_rotate(a, b, 'a');
		else
			ft_revrotate(a, b, 'a');
		i--;
	}
	return (0);
}
