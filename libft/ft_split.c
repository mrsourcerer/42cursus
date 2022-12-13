/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:02:56 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/13 07:22:39 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		if (*s != c)
			{
				count++;
				while (*s != c)
					s++;
			}
		else
			s++;
	}
//	if (count == 0)
//		return (0);
//	return (count + 1);
	return (count);
}

size_t	ft_next(char const *s, char c, size_t start)
{
	size_t	size;

	size = 0;
	s = s + start;
	while (*s == c)
	{
		s++;
		size++;
	}
	while (*s)
	{
		if (*s == c)
			return (size);
		size++;
		s++;
	}
	return (size);
}
char	*ft_add(char const *s, char c, size_t start, size_t size)
{
	char	*word;
	s = s + start;
	while (*s == c)
	{
		s++;
		size--;
	}
	word = (char *)malloc((size + 1) * sizeof(char));
	if (!word)
		return (0);
	word = ft_substr(s, 0, size);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**dict;
	size_t	start;
	size_t	size;
	size_t	i;

	count = ft_words(s, c);
	dict = (char **)malloc((count + 1) * sizeof(size_t));
	if (!dict)
		return (0);
	start = 0;
	i = 0;
	while (i < count)
	{
		size = ft_next(s, c, start);
		dict[i] = ft_add(s, c, start, size);
		start = start + size + 1;
		i++;
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
