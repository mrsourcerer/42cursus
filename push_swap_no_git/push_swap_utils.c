/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:09:43 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/15 07:25:51 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_int(t_list *a, int len)
{
	int	i;

	if (len < 2)
		return (1);
	i = 0;
	while (i < len - 1)
	{
		if (*(int *)a->content > *(int *)a->next->content)
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

int	ft_content(t_list *a)
{
	return (*(int *)a->content)
}
