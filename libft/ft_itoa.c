/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 06:58:12 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/17 10:17:56 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intsize(int n)
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

int	ft_pow(int n)
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

char	*ft_itoa(int n)
{
	size_t	size;
	size_t	i;
	char	*num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_intsize(n);
	num = (char *)malloc((size + 1) * sizeof(char));
	if (!num)
		return (0);
	i = 0;
	if (n < 0)
	{
		num[i] = '-';
		n = n * -1;
		i++;
	}
	while (i < size)
	{
		num[i] = (n / ft_pow(size - i - 1)) + '0';
		n = n % ft_pow(size - i - 1);
		i++;
	}
	num[size] = '\0';
	return (num);
}
