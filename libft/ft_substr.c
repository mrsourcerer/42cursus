/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:17:40 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/09 20:04:56 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	size = len;
	if (len > ft_strlen(s) - start)
		size = (size_t)ft_maxint(ft_strlen(s) - start, 0);
	size = size + 1;
	sub = (char *)malloc((size) * 1);
	if (!sub)
		return (0);
	if (start > ft_strlen(s))
		return (0);
	if (len > ft_strlen(s) - start)
		size = ft_strlen(s) - start + 1;
	ft_strlcpy(sub, s + start, size);
	return (sub);

	/*
	char	*sub;
	size_t	size;

	size = len + 1;
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(1 * 1);
		sub[0] = '\0';
		return (sub);
	}
	if (ft_strlen(s) - start < len)
		size = ft_strlen(s) - start + 1;
	sub = (char *)malloc(size * 1);
	if (!sub || len == 0)
		return (0);
	ft_strlcpy(sub, s + start, size);
	return (sub); */
}
