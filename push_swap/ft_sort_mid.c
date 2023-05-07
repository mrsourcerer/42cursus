/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:25:49 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/07 11:23:19 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_sort_mid(t_list **a, t_list **b)
{
	int	i;
	int	j;

	i = ft_lstsize(*a) - 3;
	j = i;
	while (i > 0)
	{
		ft_min_on_top(a, b);
		i--;
		if (ft_sorted_int(*a))
			i = 0;
		else
			ft_push(a, b, 'b');
	}
	ft_sort_min(a, b);
	while (j > 0)
	{
		ft_push(a, b, 'a');
		j--;
	}
	return (0);
}

/*
int	ft_check_special(t_list **a, t_list **b, int *ok, char c)
{
	if (!(*ok) && c == 'a')
		if (ft_min_pos(*a) == 1)
			ft_rotate(a, b, c);
	if (!(*ok) && c == 'b')
	{
		if (ft_max_pos(*b) == 1)
		{
			//ft_lstprintf(*b, 'i');
			ft_rotate(a, b, c);
			if (ft_revsorted_int(*b))
				*ok = 1;
		}
	}
	return (0);
}

int	ft_swap_what(t_list **a, t_list **b, int *a_ok, int *b_ok)
{
	int	sw_a;
	int	sw_b;

	sw_a = 0;
	sw_b = 0;
	if (ft_lstsize(*a) > 1)
		if (ft_content(*a) > ft_content((*a)->next))
			sw_a = 1;
	if (ft_lstsize(*b) > 1)
		if (ft_content(*b) < ft_content((*b)->next))
			sw_b = 1;
	if (sw_a && sw_b && !*a_ok && !*b_ok)
		ft_swap(a, b, 's');
	else if (sw_a && !*a_ok)
		ft_swap(a, b, 'a');
	else if (sw_b && !*b_ok)
		ft_swap(a, b, 'b');
	if (ft_sorted_int(*a))
		*a_ok = 1;
	if (ft_revsorted_int(*b))
		*b_ok = 1;
	ft_check_special(a, b, a_ok, 'a');
	ft_check_special(a, b, b_ok, 'b');
	return (sw_a + sw_b);
}

int	ft_rotate_what(t_list **a, t_list **b, int *a_ok, int *b_ok)
{
	int	sw_a;
	int	sw_b;

	sw_a = 0;
	sw_b = 0;
	if (ft_lstsize(*a) > 1)
		if (ft_content(*a) > ft_content (ft_lstlast(*a)))
			sw_a = 1;
	if (ft_lstsize(*b) > 1)
		if (ft_content(*b) < ft_content (ft_lstlast(*b)))
			sw_b = 1;
	if (sw_a && sw_b && !*a_ok && !*b_ok)
		ft_rotate(a, b, 'r');
	else if (sw_a && !*a_ok)
		ft_rotate(a, b, 'a');
	else if (sw_b && !*b_ok)
		ft_rotate(a, b, 'b');
	if (ft_sorted_int(*a))
		*a_ok = 1;
	if (ft_revsorted_int(*b))
		*b_ok = 1;
	return (sw_a + sw_b);
}

int	ft_revrotate_what(t_list **a, t_list **b, int *a_ok, int *b_ok)
{
	int	sw_a;
	int	sw_b;

	sw_a = 0;
	sw_b = 0;
	if (ft_lstsize(*a) > 1)
		if (ft_content(*a) < ft_content (ft_lstlast(*a)))
			sw_a = 1;
	if (ft_lstsize(*b) > 1)
		if (ft_content(*b) > ft_content (ft_lstlast(*b)))
			sw_b = 1;
	if (sw_a && sw_b && !*a_ok && !*b_ok)
		ft_revrotate(a, b, 'r');
	else if (sw_a && !*a_ok)
		ft_revrotate(a, b, 'a');
	else if (sw_b && !*b_ok)
		ft_revrotate(a, b, 'b');
	if (ft_sorted_int(*a))
		*a_ok = 1;
	if (ft_revsorted_int(*b))
		*b_ok = 1;
	return (sw_a + sw_b);
}

int	ft_sort_mid(t_list **a, t_list **b)
{
	int	a_ok;
	int	b_ok;
	int	mid;
	int	pivot;

	a_ok = 0;
	b_ok = 0;
	pivot = ft_lstsize(*a) / 2;
	mid = ft_mid_element(*a, ft_lstsize(*a));
	while (ft_lstsize(*b) < pivot)
	{
		if (ft_content(*a) < mid)
			ft_push(a, b, 'b');
		else
			ft_rotate(a, b, 'a');
		//ft_printf("________\nstack a\n");
		//ft_lstprintf(*a, 'i');
		//ft_printf("\nstack b\n");
		//ft_lstprintf(*b, 'i');
		//ft_printf("--------\n");
	}
	//ft_printf("stack a\n");
	//ft_lstprintf(*a, 'i');
	//ft_printf("\nstack b\n");
	//ft_lstprintf(*b, 'i');
	while (!a_ok || !b_ok)
	{
		if (ft_swap_what(a, b, &a_ok, &b_ok))
		{
			//ft_printf("________\nstack a\n");
			//ft_lstprintf(*a, 'i');
			//ft_printf("\nstack b\n");
			//ft_lstprintf(*b, 'i');
			//ft_printf("--------\n");
		}
		if (ft_rotate_what(a, b, &a_ok, &b_ok))
		{
			//ft_printf("________\nstack a\n");
			//ft_lstprintf(*a, 'i');
			//ft_printf("\nstack b\n");
			//ft_lstprintf(*b, 'i');
			//ft_printf("--------\n");
		}
		if (ft_revrotate_what(a, b, &a_ok, &b_ok))
		{
			//ft_printf("________\nstack a\n");
			//ft_lstprintf(*a, 'i');
			//ft_printf("\nstack b\n");
			//ft_lstprintf(*b, 'i');
			//ft_printf("--------\n");
		}
		if (ft_min_pos(*a) == 2 && ft_max_pos(*a) == 1)
			ft_rotate(a, b, 'a');
		if (ft_min_pos(*b) == 1 && ft_max_pos(*b) == 2)
			ft_rotate(a, b, 'b');
	}
	while (ft_lstsize(*b) > 0)
	{
		ft_push(a, b, 'a');
	}
	return (0);
}
*/
/*
int	ft_sort_mid(t_list **a, t_list **b)
{
	int	step_1;

	while (!ft_sorted_int(*a))
	{
		step_1 = 0;
		while (ft_lstsize(*a) > 0)
		{
			if (!ft_swap_what(a, b))
				step_1 = 1;
			if (step_1)
			{
				step_1 = 0;
				ft_push(a, b, 'b');
			}
			//ft_printf("stack a\n");
			//ft_lstprintf(*a, 'i');
			//ft_printf("\nstack b\n");
			//ft_lstprintf(*b, 'i');
		}
		step_1 = 0;
		while (ft_lstsize(*b) > 0)
		{
			if (!ft_swap_what(a, b))
				step_1 = 1;
			if (step_1)
			{
				step_1 = 0;
				ft_push(a, b, 'a');
			}
			//ft_printf("stack a\n");
			//ft_lstprintf(*a, 'i');
			//ft_printf("\nstack b\n");
			//ft_lstprintf(*b, 'i');
		}
	}
	return (0);
}*/
