/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:17:33 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/09 06:28:48 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list *args)
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
	if (c == 'u')
		ft_printf_u(va_arg(*args, unsigned int), &i);
	if (c == 'x' || c == 'X')
		ft_printf_x(va_arg(*args, unsigned int), &i, c);
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

	i = 0;
	written = 0;
	size = ft_strlen(str);
	va_start(args, str);
	while (i < size)
	{
		if (str[i] == '%')
		{
			written += ft_check(str[i + 1], &args);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			written++;
		}
		i++;
	}
	va_end (args);
	return (written);
}
