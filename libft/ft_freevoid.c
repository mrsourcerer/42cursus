/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freevoid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:03:40 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/02 21:32:09 by danlopez         ###   ########.fr       */
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

void	ft_frint(int **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}
