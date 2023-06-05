/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:13:24 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/12 06:59:04 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa_nomalloc(long n)
{
	long long		num;
	size_t			size;
	size_t			i;
	static char		str[12];
	char			*num_str;

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

void	ft_putnbr_fd(int n, int fd)
{
	ft_putstr_fd(ft_itoa_nomalloc(n), fd);
}

int	ft_putnbr(long n, int fd)
{
	int	written;

	written = ft_putstr(ft_itoa_nomalloc(n), fd);
	return (written);
}
