/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 06:58:12 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/14 07:29:37 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intsize(int n, size_t size)
{
	if (n < 0)
	{
		size++;
		n = n * -1; // restar 1 por si es min int ¿? y luego comprobar y sumar
	}
	while (n > 9)
	{
		size++;
		ft_intsize(n / 10, size);
	}
	size++;
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*num;

	size = 0;
	size = ft_intsize(n, size);

	num = "25";
	return (num);
}
