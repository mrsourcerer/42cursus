/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:17:40 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/26 17:56:50 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	if (!s)
		return (0);
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
