/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:43:08 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/13 20:48:10 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_power(int base, int power)
{
	int		i;
	size_t	num;

	i = power;
	num = 1;
	while (i > 0)
	{
		num *= base;
		i--;
	}
	return (num);
}
