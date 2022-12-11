/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:02:56 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/11 14:00:35 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count + 1);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	void	*dict;

	count = ft_words(s, c);
	dict = (void *)malloc((count + 1) * sizeof(void));
	if (!dict)
		return (0);
	if (count == 0)


	return (dict);
}
