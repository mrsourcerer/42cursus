/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:22:54 by danlopez          #+#    #+#             */
/*   Updated: 2023/06/26 06:40:38 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrf(double n, int precision, int fd)
{
	int		written;
	char	*str;

	str = ft_ftoa(n, precision);
	written = ft_putstr(str, fd);
	free(str);
	return (written);
}
