/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 06:34:50 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/08 11:33:11 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_mandelbrot(void)
{
	ft_printf("Entering mandelbrot\n");
}

int	ft_check_mandelbrot(double c_x, double c_y, int max)
{
	t_complex	c;
	t_complex	z0;
	t_complex	zn;
	int			i;

	c = ft_z(c_x, c_y);
	z0 = ft_z(0, 0);
	i = 0;
	while (i <= max)
	{
		zn = ft_z(z0.re * z0.re - z0.im * z0.im + c.re, \
				2 * z0.re * z0.im + c.im);
		if (pow(zn.re, 2.0) + pow(zn.im, 2.0) > 4)
			return (i);
		i++;
		z0 = zn;
	}
	return (max + 1);
}
