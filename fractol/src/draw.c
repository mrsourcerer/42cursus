/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 07:02:50 by danlopez          #+#    #+#             */
/*   Updated: 2023/11/06 06:51:05 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

uint8_t	ft_255(int c_x, int c_y)
{
	return ((uint8_t)(sqrt(c_x * c_x + c_y * c_y) / \
		sqrt(WIDTH * WIDTH / 4.0 + HEIGHT * HEIGHT / 4.0) * 255));
}

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
	if ((x == 0 && y == 0) || (x == WIDTH - 1 && y == HEIGHT - 1) \
		|| (x == 500 && y == 500) || (x == 0 && y == 500) || (x == 999 && y == 500))
		ft_printf("x: %i ; y: %i <--> c_x: %f c_y: %f <--> check: %i <--> max: %i <--> j_re: %f j_im: %f <--> julia: %i\n", x, y, c_x, c_y, check, vars->max, vars->j_re, vars->j_im, vars->julia);
	color.channel[0] = 0;
	if (check > vars->max)
		ft_channel(&color, 10, 10, 50);
	/*{
		ft_channel(&color, 10, 10, 50);
		color.channel[1] = 10; //red not necessary to cast = (uint8_t)255
		color.channel[2] = 10; //green not necessary to cast = (uint8_t)255
		color.channel[3] = 50; //blue not necessary to cast = (uint8_t)255
	}*/
	else
		ft_channel(&color, check * 255 / (vars->max + 1), \
					check * 200 / (vars->max + 1), 0);
	/*{
		ft_channel(&color, check * 255 / (vars->max + 1), \
					check * 200 / (vars->max + 1), 0);
		color.channel[1] = check * 255 / (vars->max + 1); //red not necessary to cast = (uint8_t)255
		color.channel[2] = check * 200 / (vars->max + 1); //green not necessary to cast = (uint8_t)255
		color.channel[3] = 0 / (vars->max + 1); //blue not necessary to cast = (uint8_t)255
	}*/
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
