/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:43:36 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/07 19:29:42 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
