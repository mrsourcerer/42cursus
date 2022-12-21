/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:27:23 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/21 07:21:01 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	int		size;

	len = ft_strlen(src);
	if (dstsize > len)
		size = len + 1;
	else
		size = dstsize;
	if (size > 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	size;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (dstsize > len_dst + len_src)
		size = len_dst + len_src + 1;
	else
		size = dstsize;
	if (dstsize > 0 && size > len_dst)
		ft_strlcpy(dst + len_dst, src, size - len_dst);
	if (dstsize > len_dst)
		size = len_dst;
	else
		size = dstsize;
	if (dstsize > 0)
		return (len_src + size);
	else
		return (len_src);
}
