/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 06:34:32 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/29 12:58:06 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_julia(void)
{
	ft_printf("Entering julia\n");
}

int	ft_check_julia(double c_x, double c_y, t_vars *vars)
{
	t_complex	c;
	t_complex	z0;
	t_complex	zn;
	int			i;

	//c = ft_z(c_x, c_y);
	//z0 = ft_z(vars->j_re, vars->j_im);
	z0 = ft_z(c_x, c_y);
	c = ft_z(vars->j_re, vars->j_im);
	i = 0;
	while (i <= vars->max)
	{
		zn = ft_z(z0.re * z0.re - z0.im * z0.im + c.re, \
				2 * z0.re * z0.im + c.im);
		if (pow(zn.re, 2.0) + pow(zn.im, 2.0) > 4)
			return (i);
		i++;
		z0 = zn;
	}
	return (vars->max + 1);
}
