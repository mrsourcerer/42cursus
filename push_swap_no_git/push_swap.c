/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:05:16 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/13 22:39:58 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_to_int(char *argv[], int **values)
{
	int		i;
	char	*p;

	i = 1;
	while (argv[i])
	{
		p = argv[i];
		if (ft_atoi(p) != ft_atol(p))
			return (-1);
		/*if (ft_atoi(p) == 0)
		{
			while (*p)
			{
				if (*p == '+' || *p == '-')
					p++;
				if (*p != '0')
					return (-1);
				p++;
			}
		}*/
		(*values)[i - 1] = (int)ft_atoi(p);
		i++;
	}
	return (0);
}

static int	ft_value_to_list(int *values, t_list **a, int len)
{
	t_list	*new;

	if (ft_duplicated(values, len))
		return (-1);
	while (len)
	{
		new = ft_lstnew(values);
		ft_lstadd_back(a, new);
		values++;
		len--;
	}
	return (0);
}

static int	ft_sort_menu(t_list **a, t_list **b, int len)
{
	if (ft_sorted_int(*a, len))
		return (0);
	if (len < 3)
	{
		ft_swap(a, b, 'a');
		return (0);
	}
	if (len < 4)
		ft_sort_min(a, b);
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		*values;

	if (argc < 2)
		return (ft_printf("Error\n"), -1);
	values = (int *)malloc((argc - 1) * sizeof(int));
	if (!values)
		return (ft_frint(&values), -1);
	if (ft_to_int(argv, &values))
		return (ft_frint(&values), ft_printf("Error\n"), -1);
	if (ft_value_to_list(values, &a, argc - 1))
		return (ft_frint(&values), ft_printf("Error\n"), -1);
	ft_lstprintf(a, 'i');
	ft_printf("________Sorting Start_______\n");
	ft_sort_menu(&a, &b, argc - 1);
	ft_printf("________Sorting End_________\n");
	ft_lstprintf(a, 'i');
	return (76);
}
