/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 08:55:14 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/11 13:44:57 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

int		ft_sort_min(t_list **a, t_list **b);
int		ft_sorted_int(t_list *a, int len);
int		ft_duplicated(int *a, int len);

void	ft_swap(t_list **a, t_list **b, char c);
void	ft_rotate(t_list **a, t_list **b, char c);
void	ft_revrotate(t_list **a, t_list **b, char c);

#endif
