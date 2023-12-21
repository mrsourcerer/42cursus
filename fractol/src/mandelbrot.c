/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 06:34:50 by danlopez          #+#    #+#             */
/*   Updated: 2023/12/21 19:26:59 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_mandelbrot(t_vars *vars)
{
	vars->julia = 0;
}

int	ft_check_mandelbrot(double c_x, double c_y, t_vars *vars)
{
	t_complex	c;
	t_complex	z0;
	t_complex	zn;
	int			i;

	c = ft_z(c_x, c_y);
	z0 = ft_z(vars->j_re, vars->j_im);
	i = 0;
	while (i <= vars->max)
	{
		zn = ft_z(pow(z0.re, 2) - pow(z0.im, 2) + c.re, \
				2 * z0.re * z0.im + c.im);
		if ((pow(zn.re, 2) + pow(zn.im, 2)) > 4)
			return (i);
		i++;
		z0 = zn;
	}
	return (vars->max + 1);
}
