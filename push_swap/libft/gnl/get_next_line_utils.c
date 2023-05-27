/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:27:23 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/03 07:07:51 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(const char *s, char c)
{
	int	i;

	i = 0;
	if (ft_len(s) == 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_free(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

char	*ft_join(char **s1, char **s2)
{
	char	*result;
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = ft_len(*s1);
	len2 = ft_len(*s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (ft_free(s1), ft_free(s2), NULL);
	i = 0;
	while (i < len1 + len2)
	{
		if (i < len1)
			result[i] = (*s1)[i];
		else
			result[i] = (*s2)[i - len1];
		i++;
	}
	result[len1 + len2] = '\0';
	return (ft_free(s1), ft_free(s2), result);
}

char	*ft_get(char *s, int start, int end)
{
	int		size;
	char	*result;
	int		i;

	if (!s)
		return (NULL);
	size = end - start + 1;
	if (size < 0)
		return (NULL);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = s[start + i];
		i++;
	}
	result[size] = '\0';
	return (result);
}
