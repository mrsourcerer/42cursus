/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:25:49 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/23 07:21:23 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap_what(t_list **a, t_list **b, int a_ok, int b_ok)
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
	if (sw_a && sw_b && !a_ok && !b_ok)
		ft_swap(a, b, 's');
	else if (sw_a && !a_ok)
		ft_swap(a, b, 'a');
	else if (sw_b && !b_ok)
		ft_swap(a, b, 'b');
	return (sw_a + sw_b);
}

int	ft_rotate_what(t_list **a, t_list **b)
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
	if (sw_a && sw_b)
		ft_rotate(a, b, 'r');
	else if (sw_a)
		ft_rotate(a, b, 'a');
	else if (sw_b)
		ft_rotate(a, b, 'b');
	return (sw_a + sw_b);
}

int	ft_revrotate_what(t_list **a, t_list **b)
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
	if (sw_a && sw_b)
		ft_revrotate(a, b, 'r');
	else if (sw_a)
		ft_revrotate(a, b, 'a');
	else if (sw_b)
		ft_revrotate(a, b, 'b');
	return (sw_a + sw_b);
}

int	ft_sort_mid(t_list **a, t_list **b)
{
	int	a_ok;
	int	b_ok;

	a_ok = 0;
	b_ok = 0;
	while (ft_lstsize(*a) > ft_lstsize(*b))
	{
		if (ft_content(*a) < 7)
			ft_push(a, b, 'b');
		ft_rotate(a, b, 'a');
	}
	while (!ft_sorted_int(*a))
	{
		ft_swap_what(a, b, a_ok, b_ok);
		//if (ft_sorted_int(*a))
		//	break ;
		ft_rotate_what(a, b);
		//if (ft_sorted_int(*a))
		//	break ;
		//ft_swap_what(a, b);
		//if (ft_sorted_int(*a))
		//	break ;
		ft_revrotate_what(a, b);
		if (ft_sorted_int(*a))
			break ;
		//ft_printf("stack a\n");
		//ft_lstprintf(*a, 'i');
	}
	while (ft_lstsize(*b) > 0)
	{
		ft_push(a, b, 'a');
	}
	return (0);
}

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
