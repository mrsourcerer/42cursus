/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_intutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 05:58:30 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/12 11:06:30 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p(size_t pointer, int *p_i)
{
	*p_i = ft_putstr("0x", 1);
	if (*p_i == -1)
		return ;
	ft_printf_xp(pointer, p_i);
}

void	ft_printf_i(int num, int *p_i)
{
	*p_i = ft_putnbr(num, 1);
}

void	ft_printf_u(unsigned int num, int *p_i)
{
	*p_i = ft_putnbr(num, 1);
}
