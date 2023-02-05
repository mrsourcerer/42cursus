/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_charutils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 06:53:04 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/05 07:08:20 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(char c, int *p_i)
{
	ft_putchar_fd(c, 1);
	(*p_i)++;
}

void	ft_printf_s(char *str, int *p_i)
{
	if (str)
	{
		ft_putstr_fd(str, 1);
		*p_i = (int)ft_strlen(str);
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		*p_i = (int)ft_strlen("(null)");
	}
}
