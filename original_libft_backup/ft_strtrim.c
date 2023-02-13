/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 08:12:16 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/26 19:14:38 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	size_t	left;
	size_t	right;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	size = ft_strlen(s1);
	left = 0;
	right = size;
	while (left < size && ft_strchr(set, s1[left]))
		left++;
	while (right > 0 && ft_strchr(set, s1[right]))
		right--;
	right++;
	if (left > right)
	{
		left = 0;
		right = 0;
	}
	return (ft_substr(s1, left, right - left));
}
