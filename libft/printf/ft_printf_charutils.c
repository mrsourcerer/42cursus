/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_charutils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 06:53:04 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/27 06:54:09 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(char c, int *p_i)
{
	*p_i = ft_putchar(c, 1);
}

void	ft_printf_s(char *str, int *p_i)
{
	if (str)
	{
		*p_i = ft_putstr(str, 1);
	}
	else
	{
		*p_i = ft_putstr("(null)", 1);
	}
}
