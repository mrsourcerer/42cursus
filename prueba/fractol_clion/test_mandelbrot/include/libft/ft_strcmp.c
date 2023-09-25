/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 07:07:48 by danlopez          #+#    #+#             */
/*   Updated: 2023/06/25 07:24:19 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	len;
	size_t	i;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
