/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:22:54 by danlopez          #+#    #+#             */
/*   Updated: 2023/06/25 12:39:32 by danlopez         ###   ########.fr       */
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

char	*ft_ftoa(double n, int precision)
{
	char	str[100];
	size_t	int_part;
	size_t	pre_part;

	int_part = ft_dsize(n) + 1;
	if (precision > 0)
		pre_part = precision + 1;
	return (str);
}

int	ft_putnbrf(double n, int precision, int fd)
{
	int	written;

	written = ft_putstr(ft_ftoa(n, precision), fd);
	return (written);
}
