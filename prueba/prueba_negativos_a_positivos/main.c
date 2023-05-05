/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 06:57:01 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/05 07:27:29 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_get_original(int **original, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		(*original)[i - 1] = atoi(argv[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	*original_list;
	int	*final_list;
	int	i;

	original_list = (int *)malloc((argc - 1) * sizeof(int));
	final_list = (int *)malloc((argc - 1) * sizeof(int));
	printf("Argc: %i\n", argc);
	ft_get_original(&original_list, argc, argv);
	i = 1;
	while (i < argc)
	{
		printf("Value: %i\n", original_list[i - 1]);
		i++;
	}
	return (0);
}
