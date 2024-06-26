/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:17:33 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/03 06:50:55 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_char(char c, va_list *args)
{
	int	i;

	i = 0;
	if (c == 'c')
		ft_printf_c(va_arg(*args, int), &i);
	if (c == 's')
		ft_printf_s(va_arg(*args, char *), &i);
	if (c == 'p')
		ft_printf_p(va_arg(*args, size_t), &i);
	if (c == 'd' || c == 'i')
		ft_printf_i(va_arg(*args, int), &i);
	if (c == 'f')
		ft_printf_f(va_arg(*args, double), &i);
	if (c == 'u')
		ft_printf_u(va_arg(*args, unsigned int), &i);
	if (c == 'x')
		ft_printf_x(va_arg(*args, unsigned int), &i, "0123456789abcdef");
	if (c == 'X')
		ft_printf_x(va_arg(*args, unsigned int), &i, "0123456789ABCDEF");
	if (c == '%')
		ft_printf_c('%', &i);
	return (i);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	i;
	int		written;
	size_t	size;
	int		tmp;

	i = 0;
	written = 0;
	size = ft_strlen(str);
	va_start(args, str);
	while (i < size)
	{
		if (str[i] == '%')
			tmp = ft_check_char(str[(i++) + 1], &args);
		else
			tmp = ft_putchar(str[i], 1);
		if (tmp == -1)
			return (-1);
		written += tmp;
		i++;
	}
	va_end (args);
	return (written);
}
