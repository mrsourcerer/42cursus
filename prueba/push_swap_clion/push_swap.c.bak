/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:05:16 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/05 10:48:24 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_duplicate(int *a, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (a[i] == a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_to_stack(char *argv[], int **a)
{
	int		i;
	char	*p;
	long	tmp;

	i = 1;
	while (argv[i])
	{
		p = argv[i];
		tmp = ft_atol(p);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (-1);
		if (tmp == 0)
		{
			while (*p)
			{
				if (*p == '+' || *p == '-')
					p++;
				if (*p != '0')
					return (-1);
				p++;
			}
		}
		(*a)[i++ - 1] = (int)tmp;
	}
	return (ft_duplicate(*a, --i));
}

int	ft_sorted_int(int *a, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		*a;
	int		*b;
	//int		i;

	if (argc < 2)
		return (ft_printf("Error\n"), -1);
	a = (int *)malloc((argc) * sizeof(int));
	b = (int *)malloc((argc) * sizeof(int));
	if (!a || !b)
		return (ft_frint(&a), ft_frint(&b), -1);
	if (ft_to_stack(argv, &a))
		return (ft_frint(&a), ft_frint(&b), ft_printf("Error\n"), -1);
	if (ft_sort_min(a, b, argc) == -1)
		return (ft_frint(&a), ft_frint(&b), ft_printf("Error\n"), -1);
/*
	i = argc;
	while (i > 1)
	{
		ft_printf("Puntero: %p - ", a);
		ft_printf("%i\n", *a);
		a++;
		i--;
	}
*/
	if (ft_sorted_int(a, argc))
		return (ft_frint(&a), ft_frint(&b), 0);
	ft_sort_min(a, b, argc);
	return (0);
}
