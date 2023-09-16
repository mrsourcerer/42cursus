/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:10:18 by danlopez          #+#    #+#             */
/*   Updated: 2023/09/16 19:00:24 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	negative;

	n = 0;
	negative = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = negative * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * negative);
}

long	ft_atol(const char *str)
{
	long	n;
	int		negative;

	n = 0;
	negative = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = negative * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * negative);
}

static double	ft_decimal(const char *str)
{
	double	dec;
	double	i;

	dec = 0;
	i = 1;
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10;
		dec = dec * 10 + (*str - '0');
		str++;
	}
	return (dec / i);
}

double	ft_atof(const char *str)
{
	double	n;
	double	negative;

	n = 0.0;
	negative = 1.0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = negative * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		n = n + ft_decimal(str);
	}
	return (n * negative);
}
