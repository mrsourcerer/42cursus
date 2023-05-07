/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:05:16 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/07 11:48:26 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicated(int *a, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (a[i] == a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

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
		(*values)[i - 1] = (int)ft_atoi(p);
		i++;
	}
	return (0);
}

static int	ft_value_to_list(int *values, int *ordered, t_list **a, int len)
{
	t_list	*new;
	int		i;
	int		j;
	int		number;

	if (ft_duplicated(values, len))
		return (-1);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (values[i] == ordered[j])
				number = j;
			j++;
		}
		values[i] = number;
		new = ft_lstnew(&values[i]);
		ft_lstadd_back(a, new);
		i++;
	}
	return (0);
}

static int	ft_sort_menu(t_list **a, t_list **b, int len)
{
	if (ft_sorted_int(*a))
		return (0);
	if (len < 3)
	{
		ft_swap(a, b, 'a');
		return (0);
	}
	if (len < 4)
		ft_sort_min(a, b);
	else if (len < 8)
		ft_sort_min_general(a, b);
	else if (len < 26)
		ft_sort_mid(a, b);
	else
		ft_sort_max(a, b);
		//ft_sort_min_general(a, b);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		*values;
	int		*ordered;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (ft_printf("Error\n"), -1);
	values = (int *)malloc((argc - 1) * sizeof(int));
	ordered = (int *)malloc((argc - 1) * sizeof(int));
	if (!values || !ordered)
		return (ft_frint(&values), ft_frint(&ordered), -1);
	if (ft_to_int(argv, &values))
		return (ft_frint(&values), ft_frint(&ordered), ft_printf("Error\n"), -1);
	ft_order_array(&ordered, values, argc - 1);
	if (ft_value_to_list(values, ordered, &a, argc - 1)) //change (or add) ordered
		return (ft_frint(&values), ft_frint(&ordered), ft_printf("Error\n"), -1);
	//ft_lstprintf(a, 'i');
	//ft_printf("________Sorting Start_______\n");
	ft_sort_menu(&a, &b, argc - 1); /*****     this is the menu              *****************/
	//ft_printf("________Sorting End_________\n");
	//ft_printf("stack a\n");
	//ft_lstprintf(a, 'i');
	//ft_printf("\nstack b\n");
	//ft_lstprintf(b, 'i');
	/*int i;
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("original: %i	   transformed: %i    ordered: %i\n", ft_atoi(argv[i + 1]), values[i], ordered[i]);
		i++;
	} */
	return (76); //to free 2 list and 2 arrays is needed
}
