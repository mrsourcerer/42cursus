/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:15:07 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/10 12:54:07 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		ok;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (needle[0] == haystack[i])
		{
			ok = 1;
			j = 0;
			while (needle[j] && haystack[i + j])
			{
				if (needle[j] != haystack[i + j])
					ok = 0;
				j++;
			}
			if (ok && i + j <= len && ft_strlen(needle) <= ft_strlen(haystack))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
