/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:05:16 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/09 22:02:20 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
*/

static int	ft_to_int(char *argv[], int **values)
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
		(*values)[i - 1] = (int)tmp;
		i++;
	}
	return (0);
}

static int	ft_value_to_list(int *values, t_list **a, int len)
{
	t_list	*new;

	while (len)
	{
		new = ft_lstnew(values);
		ft_lstadd_back(a, new);
		values++;
		len--;
	}
	return (0);
}


int	ft_sorted_int(t_list *a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (a->content > a->next->content)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	int		*values;
	int		i;
	t_list	*tmp;

	if (argc < 2)
		return (ft_printf("Error\n"), -1);
	values = (int *)malloc((argc - 1) * sizeof(int));
	if (!values)
		return (ft_frint(&values), -1);
	if (ft_to_int(argv, &values))
		return (ft_frint(&values), -1);
//		return (ft_frint(&a), ft_frint(&b), ft_printf("Error\n"), -1);
//	if (ft_sort_min(a, b, argc) == -1)
//		return (ft_frint(&a), ft_frint(&b), ft_printf("Error\n"), -1);
	if (ft_value_to_list(values, &a, argc - 1))
		return (0);
		//return (ft_frint(&values), -1); // hay que free la lista
	i = 0;
	tmp = a;
	while (tmp != NULL)
	{
		ft_printf("i: %i - Content: %i - ", i, *(int *)(tmp->content));
		ft_printf("Next Pointer: %p\n", tmp->next);
		tmp = tmp->next;
		i++;
	}
	ft_printf("Starting push_swap\n");
	if (ft_sorted_int(a, argc - 1))
		return (0);
//		return (ft_frint(&a), ft_frint(&b), 0);
//	ft_sort_min(a, b, argc);
	return (76);
}
