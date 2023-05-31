/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_math.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:08:16 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/31 07:00:17 by danlopez         ###   ########.fr       */
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
	size_t	len;

	len = ft_len(string);
	ok = 0;
	i = 0;
	while (i < len)
	{
		if (!ft_isdigit(string[i]))
			if (!((string[i] == '+' || string[i] == '-') && i == 0 && len > 1))
				ok = 1;
		i++;
	}
	return (ok);
}
