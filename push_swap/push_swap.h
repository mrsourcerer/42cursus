/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 08:55:14 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/14 08:53:52 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

int		ft_sort_min(t_list **a, t_list **b);
int		ft_sort_min_general(t_list **a, t_list **b);
int		ft_sort_mid(t_list **a, t_list **b);
int		ft_sort_max(t_list **a, t_list **b);

int		ft_sorted_int(t_list *a);
int		ft_revsorted_int(t_list *a);
int		ft_duplicated(int *a, int len);
int		ft_content(t_list *a);
int		ft_min_pos(t_list *a);
int		ft_min_on_top(t_list **a, t_list **b);

void	ft_swap(t_list **a, t_list **b, char c);
void	ft_rotate(t_list **a, t_list **b, char c);
void	ft_revrotate(t_list **a, t_list **b, char c);
void	ft_push(t_list **a, t_list **b, char c);

void	ft_order_array(int **ordered, int *values, int len);
int		ft_check_no_num(char *string);
void	ft_free_list(t_list **a);

#endif
