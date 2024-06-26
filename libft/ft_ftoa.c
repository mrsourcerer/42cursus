/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 06:37:02 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/29 13:26:35 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_dsize(double n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n = n * -1;
	}
	while (n > 9)
	{
		size++;
		n = n / 10;
	}
	size++;
	return (size);
}

static int	ft_pow(int n)
{
	int	i;

	i = 1;
	while (n > 0)
	{
		i = i * 10;
		n--;
	}
	return (i);
}

static void	ft_int_part(double d, size_t size, char *str)
{
	size_t	i;
	int		n;

	n = (int)d;
	i = 0;
	if (d < 0)
	{
		str[i] = '-';
		n = n * -1;
		i++;
	}
	while (i < size)
	{
		str[i] = (n / ft_pow(size - i - 1)) + '0';
		n = (int)n % ft_pow(size - i - 1);
		i++;
	}
}

static void	ft_pre_part(double n, size_t i_p, size_t p_p, char *str)
{
	size_t	i;
	int		size;
	int		num;

	str[i_p - 1] = '.';
	i = 0;
	if (n < 0)
		n = n * -1;
	size = (int)p_p - 1;
	n = (n - (int)n) * ft_pow(size);
	if (n - (int)n >= 0.5)
		n = n + 1;
	num = (int)n;
	while (i < p_p - 1)
	{
		str[i_p + i] = (num / ft_pow(size - i - 1)) + '0';
		num = num % ft_pow(size - i -1);
		i++;
	}
	str[i_p + p_p - 1] = '\0';
}

char	*ft_ftoa(double n, int precision)
{
	char	*str;
	size_t	int_part;
	size_t	pre_part;

	pre_part = 0;
	int_part = ft_dsize(n) + 1;
	if (precision > 0)
		pre_part = precision + 1;
	str = (char *)malloc((int_part + pre_part) * sizeof(char));
	if (!str)
		return (0);
	ft_int_part(n, int_part - 1, str);
	if (pre_part)
		ft_pre_part(n, int_part, pre_part, str);
	else
		str[int_part - 1] = '\0';
	return (str);
}
