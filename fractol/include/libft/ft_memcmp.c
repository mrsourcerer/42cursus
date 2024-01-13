/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:36:39 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/08 10:11:17 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*p_s1;
	char	*p_s2;

	p_s1 = (char *)s1;
	p_s2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)p_s1[i] != (unsigned char)p_s2[i])
			return ((unsigned char)p_s1[i] - (unsigned char)p_s2[i]);
		i++;
	}
	return (0);
}
