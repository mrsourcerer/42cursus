/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 06:57:01 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/06 13:00:34 by danlopez         ###   ########.fr       */
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

void	ft_create_final(int **final, int *original, int len)
{
	int			i;
	int			j;
	int			*tmp;
	long int	value;
	long int	anterior;

	tmp = (int *)malloc(len * sizeof(int));
	i = 0;
	anterior = -2147483649;
	while (i < len)
	{
		j = 0;
		value = 2147483647;
		while (j < len)
		{
			if (original[j] < value && original[j] > anterior)
				value = original[j];
			j++;
		}
		tmp[i] = (int)value;
		anterior = value;
		i++;
	}
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (original[i] == tmp[j])
			{
				(*final)[i] = j;
			}
			j++;
		}
		i++;
	}
	free(tmp);
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
	ft_create_final(&final_list, original_list, argc - 1);
	i = 1;
	while (i < argc)
	{
		printf("Original %i: %i\n", i, original_list[i - 1]);
		printf("Final    %i: %i\n\n", i, final_list[i - 1]);
		i++;
	}
	return (0);
}
