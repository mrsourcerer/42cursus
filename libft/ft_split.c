/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:02:56 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/12 07:25:40 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c)
			{
				count++;
				while (*s == c)
					s++;
			}
		s++;
	}
	return (count + 1);
}

size_t	ft_next(char const *s, char c, size_t start)
{
	size_t	size;

	size = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c)
			return (size);
		size++;
		s++;
	}
	return (size);
}
void	ft_add(char const *s, char c, char **dict, size_t start, size_t size)
{
	while (*s == c)
		s++;
	///////////////////////////////////////// voy aqui, malloc y dar valor

}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**dict;
	size_t	start;
	size_t	size;

	count = ft_words(s, c);
	dict = (char **)malloc((count + 1) * sizeof(size_t));
	if (!dict)
		return (0);
	start = 0;
	while (count > 0)
	{
		size = ft_next(s, c, start);
		ft_add(s, c, dict, start, size);
		start = size + 1;
		count--;
	}
/*	if (count == 1)
	{
		dict[0] = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!dict[0])
			return (0);
		dict[0] = ft_substr(s, 0, ft_strlen(s));
		return (dict);
	}
*/
	return (dict);
}
