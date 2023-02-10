/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 05:47:28 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/10 06:35:40 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_call(char **array)
{
	printf("Inside function:\n");
	printf("%s\n", *array);
	printf("%s\n", *(array + 1));
	(*array)[7] = '2'; // si quitas los parentesis no funciona
	(*array)[8] = '1'; // si quitas los parentesis no funciona
	(*array)[9] = '\0'; // si quitas los parentesis no funciona
	array[1][8] = '2';
	array[1][9] = '\0';
	*array[0] = 'X';  // sin embargo de esta manera si puedes modificar el primer caracter
	*(array + 1)[0] = 'X';

	printf("%s\n", *array);
	printf("%s\n", *(array + 1));
}

int	main(void)
{
	char	**str_array;
	char	*str1;
	char	*str2;
	char	s1[] = "String 1";
	char	s2[] = "String 2";
	int		i;

	str1 = (char *)malloc(11 * sizeof(char));
	str2 = (char *)malloc(11 * sizeof(char));
	str_array = (char **)malloc(3 * sizeof(size_t));
	i = 0;
	while (s1[i])
	{
		str1[i] = s1[i];
		str2[i] = s2[i];
		i++;
	}
	str_array[0] = str1;
	//str_array[0] = s1; //con estos hay comportamientos raros al salirte de la longitud
	str_array[1] = str2;
	//str_array[1] = s2; // con estos hay comportamientos raros al salirte de la longitud
	str_array[2] = NULL;
	printf("%s\n", *str_array);
	printf("%s\n",*(str_array + 1));
	ft_call(str_array);
	printf("Out of function:\n");
	printf("%s\n", *str_array);
	printf("%s\n",*(str_array + 1));
	return (0);
}
