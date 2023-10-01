/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:14:42 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/01 10:37:11 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_color	ft_color(t_vars *vars)
{
	t_color	color;

	color.channel[0] = 0;
	color.channel[(0 + vars->color) % 3 + 1] = (uint8_t)255; //red
	color.channel[(1 + vars->color) % 3 + 1] = (uint8_t)0; //green
	color.channel[(2 + vars->color) % 3 + 1] = (uint8_t)0; //blue
	return (color);
}

void	ft_put_pixel(t_vars *vars, int x, int y, t_color color)
{
	int	offset;

	offset = y * vars->img->line_length + x * (vars->img->bits_per_pixel / 8);
	vars->img->addr[offset] = color.channel[3];
	vars->img->addr[++offset] = color.channel[2];
	vars->img->addr[++offset] = color.channel[1];
	vars->img->addr[++offset] = color.channel[0];
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

	y = HEIGHT;
	while (y > 0)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = ft_color(vars);
			ft_put_pixel(vars, x++, HEIGHT - y, color);
		}
		y--;
	}
	ft_final_draw(vars);
}
