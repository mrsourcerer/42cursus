/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 07:26:51 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/20 07:26:51 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	char	*tmp;
	int		len;

	tmp = "Hello, World!\n";
	len = ft_len(tmp);
	printf("%s %i", tmp, len);
	return (0);
}
