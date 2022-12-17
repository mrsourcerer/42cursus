/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:02:56 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/17 14:18:09 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> //////////////////////////////////////////////////////////////

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
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (count);
}

size_t	ft_next(char const *s, char c, size_t start)
{
	size_t	size;

	size = 0;
	s = s + start;
	//printf("size prev: %zu\n", size);
	while (*s == c)
	{
		s++;
		size++;
	}
	//printf("size antes while: %zu\n", size);
	while (*s)
	{
		if (*s == c)
			return (size);
		size++;
		s++;
		//printf("size en while: %zu\n", size);
	}
	//printf("size si no encuentra: %zu\n", size);
	return (size);
}

char	**ft_free(size_t i, char **dict)
{
	i--;
	while (i > 0)
	{
		free(dict[i]);
		i--;
	}
	return (0);
}

char	*ft_add(char const *s, char c, size_t start, size_t size)
{
	char	*word;

	s = s + start;
	while (*s == c)
	{
		s++;
		size--;
		//printf("resta un size\n");
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
	//printf("cant words: %zu\n", count);
	dict = (char **)malloc((count + 1) * sizeof(size_t));
	if (!dict)
		return (0);
	start = 0;
	i = 0;
	while (i < count)
	{
		size = ft_next(s, c, start);
		//printf("palabra: %zu | size: %zu\n", i, size);
		dict[i] = ft_add(s, c, start, size);
		if (!dict[i])
		{
			ft_free(i, dict);
			free(dict[0]);
			return (0);
		}
		start = start + size + 1;
		i++;
	}
	dict[count] = 0;
	return (dict);
}
