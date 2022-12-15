/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 06:58:12 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/15 07:26:24 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intsize(int n)
{
	size_t size;

	size = 0;
	if (n < 0)
	{
		size++;
		n = n * -1; // restar 1 por si es min int ¿? y luego comprobar y sumar
	}
	while (n > 9)
	{
		size++;
		n = n / 10;
	}
	size++;
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*num;

	size = ft_intsize(n);
	num = (char *)malloc((size + 1) * sizeof(char));
	if (!num)
		return (0);
	// falta rellenar num con el resto de valores
	num[size] = '\0';
	return (num);
}
