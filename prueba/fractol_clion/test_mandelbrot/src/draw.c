/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:14:42 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/08 12:45:33 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

uint8_t	ft_255(int c_x, int c_y)
{
	return ((uint8_t)(sqrt(c_x * c_x + c_y * c_y) / sqrt(WIDTH * WIDTH / 4.0 + HEIGHT * HEIGHT / 4.0) * 255));
}

double	ft_get_cx(int x)
{
	double	c_x;

	c_x = (2 * x - WIDTH) / (WIDTH / 2.0);
	return (c_x);
}

double	ft_get_cy(int y)
{
	double	c_y;

	c_y = (2 * y - HEIGHT) / (HEIGHT / 2.0);
	return (c_y);
}

t_color	ft_color(t_vars *vars, int x, int y)
{
	t_color	color;
	double	c_x;
	double	c_y;
	int		check;

	c_x = ft_get_cx(x);
	c_y = ft_get_cy(y);
	//if (x == 250 && y >= 0)
	//	ft_printf("x: %i c_x: %f ; y: %i c_y: %f\n", x, c_x, y, c_y);
	check = ft_check_mandelbrot(c_x, c_y, vars->max);
	if (check > vars->max)
	{
		color.channel[0 + vars->color] = 0;
		color.channel[1] = 10; //red not necessary to cast = (uint8_t)255
		color.channel[2] = 10; //green not necessary to cast = (uint8_t)255
		color.channel[3] = 50; //blue not necessary to cast = (uint8_t)255
	}
	else
	{
		color.channel[0 + vars->color] = 0;
		color.channel[1] = check * 255 / (vars->max + 1); //red not necessary to cast = (uint8_t)255
		color.channel[2] = check * 200 / (vars->max + 1); //green not necessary to cast = (uint8_t)255
		color.channel[3] = 0 / (vars->max + 1); //blue not necessary to cast = (uint8_t)255
	}
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
