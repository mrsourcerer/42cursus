/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:40:37 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/12 14:02:44 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	ft_printf_x(unsigned int num, int *p_i, char c)
{
	if (num >= 16)
		ft_printf_x(num / 16, p_i, c);
	if (c > 65 && c < 90)
	{
		if (ft_putchar((char) ft_toupper(BASE[num % 16]), 1) == -1)
		{
			*p_i = -1;
			return ;
		}
		(*p_i)++;
	}
	else
	{
		if (ft_putchar(BASE[num % 16], 1) == -1)
		{
			*p_i = -1;
			return ;
		}
		(*p_i)++;
	}
}


static int	ft_count_hex(unsigned int num)
{
	int	cyphers;

	cyphers = num / 16;
	if (num % 16 != 0)
		cyphers++;
	return (cyphers);
}
*/
void	ft_printf_x(unsigned int num, int *p_i)
{
	if (num >= 16)
		ft_printf_x(num / 16, p_i);
	*p_i += ft_putchar(BASE[num % 16], 1);
}

void	ft_printf_xup(unsigned int num, int *p_i)
{
	if (num >= 16)
		ft_printf_xup(num / 16, p_i);
	*p_i += ft_putchar(BASEUP[num % 16], 1);
}

void	ft_printf_xp(size_t num, int *p_i)
{
	if (num >= 16)
		ft_printf_xp(num / 16, p_i);
	*p_i += ft_putchar(BASE[num % 16], 1);
}
