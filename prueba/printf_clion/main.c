/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:56:52 by danlopez          #+#    #+#             */
/*   Updated: 2023/01/30 22:03:58 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		size;

	setbuf(stdout, NULL);
	printf("Custom:   *");
	size = ft_printf("Texto base ");
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base ");
	printf("* fin original\n");
	printf("Escrito: %i\n", size);
	return (0);
}
