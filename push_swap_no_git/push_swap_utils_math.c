/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_math.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:08:16 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/30 21:34:15 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mid_element(t_list *a, int size)
{
	t_list	*l_tmp;
	t_list	*l_mid;
	int		i;

	l_mid = a;
	while (l_mid)
	{
		i = 0;
		l_tmp = a;
		while (l_tmp)
		{
			if (ft_content(l_tmp) < ft_content(l_mid))
				i++;
			l_tmp = l_tmp->next;
		}
		if (i == size / 2)
			return (ft_content(l_mid));
		l_mid = l_mid->next;
	}
	return (0);
}
