/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:57:46 by bde-mada          #+#    #+#             */
/*   Updated: 2023/04/24 17:11:41 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_calc(double re, double im)
{
	t_complex	z;

	z.re = re;
	z.im = im;
	return (z);
}

int	calc_mandelbrot(t_param *param)
{
	int			i;
	t_complex	z;

	i = 0;
	z = complex_calc(param->c.re, param->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < param->max_iter)
	{
		z = complex_calc(pow(z.re, 2.0) - pow(z.im, 2.0) + param->c.re, \
						2.0 * z.re * z.im + param->c.im);
		i++;
	}
	return (i);
}

/* int	calc_mandelbrot(t_param *param)
{
	int			i;
	double		zrsqr;
	double		zisqr;
	t_complex	z;

	i = 0;
	z = complex_calc(param->c.re, param->c.im);
	zrsqr = pow(z.re, 2);
	zisqr = pow(z.im, 2);
	while (zrsqr + zisqr <= 4 && i < param->max_iter)
	{
		z = complex_calc(zrsqr - zisqr + param->c.re, \
						pow((z.re + z.im), 2) - zrsqr - zisqr + param->c.im);
		zrsqr = pow(z.re, 2);
		zisqr = pow(z.im, 2);
		i++;
	}
	return (i);
} */

int	calc_julia(t_param *param)
{
	int			i;
	t_complex	z;

	i = 0;
	z = complex_calc(param->c.re, param->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < param->max_iter)
	{
		z = complex_calc(pow(z.re, 2.0) - pow(z.im, 2.0) + param->k.re, \
						2.0 * z.re * z.im + param->k.im);
		i++;
	}
	return (i);
}

int	calc_mandelbar(t_param *param)
{
	int			i;
	t_complex	z;

	i = 0;
	z = complex_calc(param->c.re, param->c.im);
	while (pow(z.re, 2) + pow(z.im, 2) <= 4 && i < param->max_iter)
	{
		z = complex_calc(pow(z.re, 2.0) - pow(z.im, 2.0) + param->c.re, \
						-2.0 * z.re * z.im + param->c.im);
		i++;
	}
	return (i);
}

int	calc_burning_ship(t_param *param)
{
	int			i;
	t_complex	z;

	i = 0;
	z = complex_calc(param->c.re, param->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < param->max_iter)
	{
		z = complex_calc(pow(z.re, 2.0) - pow(z.im, 2.0) + param->c.re, \
						-2.0 * fabs(z.re * z.im) + param->c.im);
		i++;
	}
	return (i);
}
