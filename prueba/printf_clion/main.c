/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:56:52 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/13 22:41:01 by danlopez         ###   ########.fr       */
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
	char			*p_null;

	num = 42;
	u_num = 4147483649;
	//p_num = 0;
	p_num = &num;
	//p_num = 15;
	p_null = NULL;

	setbuf(stdout, NULL);
	printf("Texto base...\n");
	printf("Custom:   *");
	size = ft_printf("Texto base:");
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base:");
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("tipo c...\n");
	printf("Custom:   *");
	size = ft_printf("Texto base: %c", '%');
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %c", '%');
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("tipo s...\n");
	printf("Custom:   *");
	size = ft_printf("Texto base: %s", "string");
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %s", "string");
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("Custom:   *");
	size = ft_printf(" NULL %s NULL ", p_null);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf(" NULL %s NULL ", p_null);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("tipo p...\n");
	printf("Custom:   *");
	size = ft_printf("Texto base: %p", p_num);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Custom:   *");
	size = ft_printf("Texto base: %p", NULL);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %p", p_num);
	printf("* fin original\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %p", NULL);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("tipo i...\n");
	printf("Custom:   *");
	size = ft_printf("Texto base: %i", num);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %i", num);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("tipo d...\n");
	printf("Custom:   *");
	size = ft_printf("Texto base: %d", num);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %d", num);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("tipo u...\n");
	printf("Custom:   *");
	size = ft_printf("Texto base: %u", u_num);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %u", u_num);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("tipo x...\n");
	printf("Custom:   *");
	size = ft_printf("Texto base: %x", u_num);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %x", u_num);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("tipo X...\n");
	printf("Custom:   *");
	size = ft_printf("Texto base: %X", u_num);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("Texto base: %X", u_num);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	printf("variado buscando errores...\n");
	printf("Custom:   *");
	size = ft_printf("%x", 16);
	printf("* fin custom\n");
	printf("Escrito: %i\n", size);
	printf("Original: *");
	size = printf("%x", 16);
	printf("* fin original\n");
	printf("Escrito: %i\n\n", size);

	return (0);
}
