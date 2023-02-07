/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_intutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 05:58:30 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/07 07:23:55 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(long double num)
{
	int			i;
	size_t		pot;
	int			sign;
	long double	tmp;

	i = 0;
	sign = 1;
	if (num < 0)
		sign = -1;
	tmp = num * sign;
	pot = 1;
	while (tmp != 0)
	{
		if ((int)(tmp / pot) == 0)
			return (i + (1 - sign) / 2);
		i++;
		pot = pot * 10;
	}
	return (1);
}

void	ft_printf_p(size_t pointer, int *p_i)
{
	//ft_putnbr_fd(pointer, 1);
	(*p_i) = (*p_i) + 2;
	ft_putstr_fd("0x", 1);
	ft_printf_x(pointer, p_i, 'p');
}

void	ft_printf_i(int num, int *p_i)
{
	ft_putnbr_fd(num, 1);
	*p_i = ft_numlen(num);
}

void	ft_printf_u(unsigned int num, int *p_i)
{
	ft_putnbr_u_fd(num, 1);
	*p_i = ft_numlen(num);
}
