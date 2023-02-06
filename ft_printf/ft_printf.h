/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:32:01 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/05 11:55:12 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(char const *str, ...);
void	ft_printf_c(char c, int *p_i);
void	ft_printf_s(char *str, int *p_i);
void	ft_printf_p(size_t pointer, int *p_i);
void	ft_printf_i(int num, int *p_i);
void	ft_printf_u(unsigned int num, int *p_i);
void	ft_putnbr_u_fd(unsigned int n, int fd);

#endif
