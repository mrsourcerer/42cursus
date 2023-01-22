/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:27:23 by danlopez          #+#    #+#             */
/*   Updated: 2023/01/22 13:51:33 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_check(const char *s, char c)
{
	int	i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_remain(char **s, int cut)
{
	char	*tmp;
	int		i;
	size_t	size;

	size = ft_strlen(*s) - cut;
	tmp = (char *)malloc((size) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (*s[i + cut + 1])
	{
		tmp[i] = *s[i + cut + 1];
		i++;
	}
	tmp[size - 1] = '\0';
	free(*s);
	*s = NULL;
	*s = tmp;
	tmp = NULL;
	return (*s);
}

char	*ft_subs(char **s)
{
	int		i;
	int		cut;
	char	*subs;
	char	*tmp;

	cut = ft_check(*s, '\n');
	subs = (char *)malloc((cut + 2) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (i <= cut)
	{
		subs[i] = *s[i];
		i++;
	}
	subs[cut + 1] = '\0';
	tmp = ft_remain(&*s, cut);
	free(*s);
	*s = tmp;
	if (!*s)
		return (NULL);
	tmp = NULL;
	return (subs);
}
