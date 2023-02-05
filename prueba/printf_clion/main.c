/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:56:52 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/05 13:31:58 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int				size;
	int				num;
	unsigned int	u_num;
	int				*p_num;

	num = -1;
	u_num = 2147483649;
	p_num = &num;

	setbuf(stdout, NULL);
	printf("Custom:   *");
	size = ft_printf("Texto base:");
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base:");
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("Custom:   *");
	size = ft_printf("Texto base: %c", '%');
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %c", '%');
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("Custom:   *");
	size = ft_printf("Texto base: %s", "string");
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %s", "string");
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("Custom:   *");
	size = ft_printf(" NULL %s NULL ", NULL);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf(" NULL %s NULL ", NULL);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("Custom:   *");
	size = ft_printf("Texto base: %p", p_num);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %p", p_num);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("Custom:   *");
	size = ft_printf("Texto base: %i", num);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %i", num);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("Custom:   *");
	size = ft_printf("Texto base: %d", num);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %d", num);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("Custom:   *");
	size = ft_printf("Texto base: %u", u_num);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %u", u_num);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	return (0);
}
