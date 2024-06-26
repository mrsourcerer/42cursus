/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:02:56 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/03 06:44:37 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c)
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

static size_t	ft_next(char const *s, char c, size_t start)
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

static void	ft_free_dict(size_t i, char **dict)
{
	if (i > 0)
		i--;
	while (i > 0)
	{
		free(dict[i]);
		i--;
	}
	free(dict[0]);
	free(dict);
}

static char	*ft_add(char const *s, char c, size_t start, size_t size)
{
	char	*word;

	s = s + start;
	while (*s == c)
	{
		s++;
		size--;
	}
	word = ft_substr(s, 0, size);
	if (!word)
		return (0);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**dict;
	size_t	start;
	size_t	size;
	size_t	i;

	if (!s)
		return (0);
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
		if (!dict[i])
			return (ft_free_dict(i, dict), (char **)0);
		start = start + size + 1;
		i++;
	}
	return (dict[count] = 0, dict);
}
