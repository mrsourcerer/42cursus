/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 07:02:50 by danlopez          #+#    #+#             */
/*   Updated: 2023/12/21 19:44:55 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_color	ft_color(t_vars *vars, int x, int y)
{
	t_color	color;
	double	c_x;
	double	c_y;
	int		check;

	c_x = ft_get_cx(x, vars);
	c_y = ft_get_cy(y, vars);
	if (vars->julia)
		check = ft_check_julia(c_x, c_y, vars);
	else
		check = ft_check_mandelbrot(c_x, c_y, vars);
	color.channel[0] = 0;
	if (check > vars->max)
		ft_channel(&color, 255, 255, 255);
	else
		ft_channel(&color, check % 7 * 255 / 7, check % 15 * 255 / 15, \
				check % 16 * 255 / 16);
	return (color);
}

void	ft_put_pixel(t_vars *vars, int x, int y, t_color color)
{
	int	offset;

	offset = y * vars->img->line_length + x * (vars->img->bits_per_pixel / 8);
	vars->img->addr[offset] = (char)color.channel[3];
	vars->img->addr[++offset] = (char)color.channel[2];
	vars->img->addr[++offset] = (char)color.channel[1];
	vars->img->addr[++offset] = (char)color.channel[0];
}

void	ft_final_draw(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	ft_draw(t_vars *vars)
{
	t_color	color;
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = ft_color(vars, x, y);
			ft_put_pixel(vars, x++, y, color);
		}
		y++;
	}
	ft_final_draw(vars);
}
