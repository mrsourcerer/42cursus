/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:05:16 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/03 07:22:55 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	ft_to_stack(char *argv[], int **a)
{
	size_t	i;
	char	*p;
	int		tmp;

	i = 1;
	while (argv[i])
	{
		p = argv[i];
		tmp = ft_atoi(p);
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
		(*a)[i - 1] = tmp;
		i++;
	}
	(*a)[i - 1] = NULL; // mala idea hacer un int = (void *)0
	return (0);
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;

	if (argc < 2)
		return (-1);
	a = (int *)malloc((argc + 1) * sizeof(int));
	b = (int *)malloc((argc + 1) * sizeof(int));
	if (!a || !b)
		return (ft_frint(&a), ft_frint(&b), -1);
	if (ft_to_stack(argv, &a))
		return (ft_frint(&a), ft_frint(&b), ft_printf("Error\n"), -1);
	while (*a) // ver de que manera imprimir todos aunque alguno sea 0
	{
		ft_printf("%i\n", *a);
		a++;
	}
	return (0);
}
