/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:22:33 by bde-mada          #+#    #+#             */
/*   Updated: 2023/04/18 11:49:54 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_printf(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr_printf("(null)");
		return (6);
	}
	while (s[i])
	{
		ft_putchar_printf(s[i]);
		i++;
	}
	return (i);
}

int	ft_puthex_printf(unsigned int nb, char formatter)
{
	unsigned int		div;
	unsigned int		num;
	unsigned int		printed;

	div = 1;
	num = nb;
	printed = 0;
	if (nb < 0)
	{
		printed += ft_putchar_printf('-');
		num = -nb;
	}
	while (nb / div >= 16)
		div *= 16;
	while (div >= 1)
	{
		if (formatter == 'x')
			printed += ft_putchar_printf("0123456789abcdef"[nb / div]);
		else
			printed += ft_putchar_printf("0123456789ABCDEF"[nb / div]);
		nb %= div;
		div /= 16;
	}
	return (printed);
}

int	ft_address_printf(unsigned long long nb)
{
	unsigned long long		div;
	unsigned long long		num;
	unsigned int			printed;

	write(1, "0x", 2);
	div = 1;
	num = nb;
	printed = 2;
	while (nb / div >= 16)
		div *= 16;
	while (div > 1)
	{
		printed += ft_putchar_printf("0123456789abcdef"[nb / div]);
		nb %= div;
		div /= 16;
	}
	printed += ft_putchar_printf("0123456789abcdef"[nb]);
	return (printed);
}

int	ft_putnbr_printf(int value)
{
	unsigned int	div;
	unsigned int	nb;
	unsigned int	printed;

	div = 1;
	nb = value;
	printed = 0;
	if (value < 0)
	{
		printed += ft_putchar_printf('-');
		nb = -value;
	}
	while (nb / div >= 10)
		div *= 10;
	while (div > 1)
	{
		printed += ft_putchar_printf((nb / div) + '0');
		nb %= div;
		div /= 10;
	}
	printed += ft_putchar_printf(nb + '0');
	return (printed);
}

int	ft_putnbr_unsig_printf(unsigned int nb)
{
	unsigned int	div;
	unsigned int	printed;

	div = 1;
	printed = 0;
	while (nb / div >= 10)
		div *= 10;
	while (div > 1)
	{
		printed += ft_putchar_printf((nb / div) + '0');
		nb %= div;
		div /= 10;
	}
	printed += ft_putchar_printf(nb + '0');
	return (printed);
}
