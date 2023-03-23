/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 08:55:14 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/23 07:17:25 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

int		ft_sort_min(t_list **a, t_list **b);
int		ft_sort_min_general(t_list **a, t_list **b);
int		ft_sort_min_four(t_list **a, t_list **b);
int		ft_sort_min_five(t_list **a, t_list **b);

int		ft_sort_mid(t_list **a, t_list **b);
int		ft_swap_what(t_list **a, t_list **b, int a_ok, int b_ok);
int		ft_rotate_what(t_list **a, t_list **b, int a_ok, int b_ok);
int		ft_revrotate_what(t_list **a, t_list **b, int a_ok, int b_ok);

int		ft_sorted_int(t_list *a);
int		ft_duplicated(int *a, int len);
int		ft_content(t_list *a);
int		ft_min_pos(t_list *a);
int		ft_min_on_top(t_list **a, t_list **b);

void	ft_swap(t_list **a, t_list **b, char c);
void	ft_rotate(t_list **a, t_list **b, char c);
void	ft_revrotate(t_list **a, t_list **b, char c);
void	ft_push(t_list **a, t_list **b, char c);

#endif
