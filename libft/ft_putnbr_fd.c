/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:13:24 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/16 07:30:15 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putn(long n, int fd)
{
	if (n > 9)
	{
		ft_putn(n / 10, fd);
		ft_putchar_fd((int)(n % 10) + '0', fd);
	}
	else
		ft_putchar_fd((int)n + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		num = num * -1;
		ft_putchar_fd('-', fd);
	}
	while(num > 9)
	{
		ft_putn(num, fd);
	}

/*	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
	free(str);
	*/
}
