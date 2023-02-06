/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 06:08:02 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/06 06:08:31 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intsize_nomalloc(long n)
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

static int	ft_pow_nomalloc(int n)
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

static char	*ft_itoa_nomalloc(unsigned int n)
{
	long		num;
	size_t		size;
	size_t		i;
	static char	str[12];
	char		*num_str;

	num = n;
	size = ft_intsize_nomalloc(num);
	num_str = str;
	i = 0;
	if (num < 0)
	{
		num_str[i] = '-';
		num = num * -1;
		i++;
	}
	while (i < size)
	{
		num_str[i] = (num / ft_pow_nomalloc(size - i - 1)) + '0';
		num = num % ft_pow_nomalloc(size - i - 1);
		i++;
	}
	num_str[size] = '\0';
	return (str);
}

void	ft_putnbr_u_fd(unsigned int n, int fd)
{
	ft_putstr_fd(ft_itoa_nomalloc(n), fd);
}
