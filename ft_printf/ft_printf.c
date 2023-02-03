/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:17:33 by danlopez          #+#    #+#             */
/*   Updated: 2023/01/30 22:09:25 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list *args)
{
	int	i;

	i = 0;
	if (c == 'c')
		ft_printf_c(va_arg(*args, int), &i);
	return (i);
}

int	ft_special(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'd')
		return (1);
	if (c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == '%')
		return (1);
	return (0);
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
	return (written + 1);
}
