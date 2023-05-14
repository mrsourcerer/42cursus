/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_math.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:08:16 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/14 09:38:40 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_array(int **ordered, int *values, int len)
{
	int			i;
	int			j;
	int			value;
	long int	last;

	i = 0;
	last = -2147483649;
	while (i < len)
	{
		j = 0;
		value = 2147483647;
		while (j < len)
		{
			if (values[j] < value && values[j] > last)
				value = values[j];
			j++;
		}
		(*ordered)[i] = (int)value;
		last = (int)value;
		i++;
	}
}

int	ft_check_no_num(char *string)
{
	int		ok;
	size_t	i;

	ok = 0;
	i = 1;
	while (i < ft_len(string))
	{
		if (!ft_isdigit(string[i]))
			ok = 1;
		i++;
	}
	return (ok);
}
