/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:40:37 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/13 22:37:52 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_count_hex(size_t num)
{
	int	cyphers;

	cyphers = 0;
	if (num == 0)
		cyphers++;
	while (num > 0)
	{
		num = num / 16;
		cyphers++;
	}
	return (cyphers);
}

void	ft_printf_x(unsigned int num, int *p_i, char *base)
{
	int	tmp;
	int	cyphers;

	cyphers = ft_count_hex(num);
	while (cyphers > 0)
	{
		tmp = ft_putchar(base[num / ft_power(16, cyphers - 1)], 1);
		if (tmp == -1)
		{
			*p_i = -1;
			return ;
		}
		num = num % ft_power(16, cyphers -1);
		cyphers--;
		*p_i += tmp;
	}
}

void	ft_printf_xp(size_t num, int *p_i, char *base)
{
	int	tmp;
	int	cyphers;

	cyphers = ft_count_hex(num);
	while (cyphers > 0)
	{
		tmp = ft_putchar(base[num / ft_power(16, cyphers - 1)], 1);
		if (tmp == -1)
		{
			*p_i = -1;
			return ;
		}
		num = num % ft_power(16, cyphers -1);
		cyphers--;
		*p_i += tmp;
	}
}
