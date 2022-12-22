/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:27:23 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/22 07:20:17 by danlopez         ###   ########.fr       */
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (!src && !dst)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
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

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = (char *)malloc((ft_strlen(s1) + 1) * 1);
	if (!dst)
		return (0);
	ft_strlcpy(dst, s1, (size_t)ft_strlen(s1) + 1);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	size = len;
	if (len + start > ft_strlen(s))
	{
		if (start > ft_strlen(s))
			size = 0;
		else
			size = ft_strlen(s) - start;
	}
	sub = (char *)malloc((size + 1) * 1);
	if (!sub)
		return (0);
	if (start > ft_strlen(s))
		sub[0] = '\0';
	else
		ft_strlcpy(sub, s + start, size + 1);
	return (sub);
}
