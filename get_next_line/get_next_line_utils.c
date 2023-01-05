/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:27:23 by danlopez          #+#    #+#             */
/*   Updated: 2023/01/05 09:08:19 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	size;

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
