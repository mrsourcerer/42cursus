/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 06:34:50 by danlopez          #+#    #+#             */
/*   Updated: 2023/11/09 20:00:53 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_mandelbrot(t_vars *vars)
{
	ft_printf("Entering mandelbrot\n");
	vars->julia = 0;
}

int	ft_check_mandelbrot(double c_x, double c_y, t_vars *vars)
{
	t_complex	c;
	t_complex	z0;
	t_complex	zn;
	int			i;

	c = ft_z(c_x, c_y); //this was ok
	z0 = ft_z(vars->j_re, vars->j_im); //this was ok
	//z0 = ft_z(0, 0);
	//z0 = ft_z(c_x, c_y);
	//c = ft_z(0, 0);
	ft_printf("c_x: %f c_y: %f z0.re: %f z0.im: %f ", c_x, c_y, z0.re, z0.im);
	i = 0;
	while (i <= vars->max)
	{
		zn = ft_z(z0.re * z0.re + z0.im * z0.im + c.re,2 * z0.re * z0.im + c.im);
		ft_printf("zn.re: %f zn.im: %f i: %i ", zn.re, zn.im, i);
		if ((pow(zn.re, 2.0) + pow(zn.im, 2.0)) > 4)
			//return (i);
			return (ft_printf("\n", i), i);
		i++;
		z0 = zn;
	}
	ft_printf("i: %i\n", vars->max + 1);
	return (vars->max + 1);
}
