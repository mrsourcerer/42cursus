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

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 0);
		write(0, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		size;
	//int		i;

	//i = 0;
	va_start(args, str);

	size = ft_check(va_arg(args, char *));

	va_end (args);
	return (size);
}
