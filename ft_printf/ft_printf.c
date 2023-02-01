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
#include <stdio.h>

/*
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
*/
int	ft_printf(char const *str, ...)
{
	//va_list	args;
	//char	*base;
	int		i;

	i = 0;
	//va_start(args, str);
	//base = va_arg(args, char *);
	while (str[i])
	{
		//ft_putchar_fd(str[i], 0);
		//write(1, &str[i], 1);
		ft_putchar_fd(str[i], 1);
		i++;
	}
	//va_end (args);
	return (i);
}
