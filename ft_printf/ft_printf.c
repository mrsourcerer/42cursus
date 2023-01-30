/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:17:33 by danlopez          #+#    #+#             */
/*   Updated: 2023/01/30 06:14:12 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(void)
{
	write(0,"1-",2);
	ft_putchar_fd('C', 0);
	write(0,"\n2-",3);
	ft_putnbr_fd(ft_strlen("Hola mundo\n"),0);
	write(0, "3-", 2);
	write(0, "Hola mundo\n", 11);
	return (0);
}
