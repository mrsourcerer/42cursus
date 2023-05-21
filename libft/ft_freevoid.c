/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freevoid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:03:40 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/21 10:33:49 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freevoid(void **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}

void	ft_frint(int **i)
{
	if (*i)
	{
		free(*i);
		*i = NULL;
	}
}

void	ft_freestr(char **str)
{
	char	**tmp;

	tmp = str;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(str);
	str = NULL;
}
