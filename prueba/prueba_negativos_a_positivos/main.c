/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 06:57:01 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/04 07:26:49 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_get_original(int **original, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		*(original[i - 1]) = atoi(argv[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	*original_list;
	int	*final_list;

	original_list = (int *)malloc(argc * sizeof(int));
	final_list = (int *)malloc(argc * sizeof(int));
	printf("Argc: %i\n", argc);
	ft_get_original(&original_list, argc, argv);
	while (original_list)
	{
		printf("Value: %i\n", *original_list);
		original_list++;
	}
	return (0);
}
