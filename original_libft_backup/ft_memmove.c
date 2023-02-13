/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:41:15 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/06 12:38:17 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (d > s)
	{
		while (len > 0 && !(!dst && !src))
		{
			d[len - 1] = s[len -1];
			len--;
		}
	}
	else
	{
		while (i < len && !(!dst && !src))
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
