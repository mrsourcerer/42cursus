/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:40:37 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/09 06:25:08 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_x(unsigned int num, int *p_i, char c)
{
	if (num >= 16)
		ft_printf_x(num / 16, p_i, c);
	if (c > 65 && c < 90)
		ft_putchar_fd(ft_toupper(BASE[num % 16]), 1);
	else
		ft_putchar_fd(BASE[num % 16], 1);
	(*p_i)++;
}

void	ft_printf_xp(size_t num, int *p_i)
{
	if (num >= 16)
		ft_printf_xp(num / 16, p_i);
	ft_putchar_fd(BASE[num % 16], 1);
	(*p_i)++;
}
