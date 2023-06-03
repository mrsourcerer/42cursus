/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:28:02 by bde-mada          #+#    #+#             */
/*   Updated: 2023/04/25 19:30:40 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/* t_color	get_color2(int i, t_param *param)
{
	t_color	color;
	double	prop;

	if (i == param->max_iter)
	{
		color.channel[0] = 0;
		color.channel[1] = 0;
		color.channel[2] = 0;
		color.channel[3] = 0;
		return (color);
	}
	prop = (double)i / param->max_iter;
	color.channel[0] = 0;
	color.channel[(0 + param->color) % 3 + 1] = \
		(uint8_t)(0.9 * pow(prop, 2.1) * 255);
	color.channel[(1 + param->color) % 3 + 1] = \
		(uint8_t)(0.7 * pow((0.7 - fabs(prop)), 1.5) * 255);
	color.channel[(2 + param->color) % 3 + 1] = \
		(uint8_t)(0.4 * pow(1 - prop, 3) * 255);
	return (color);
} */

static t_color	get_color(int i, t_param *param)
{
	t_color	color;
	double	prop;
	double	aux[2];

	if (i == param->max_iter)
	{
		color.channel[0] = 0;
		color.channel[1] = 0;
		color.channel[2] = 0;
		color.channel[3] = 0;
		return (color);
	}
	prop = (double)i / param->max_iter;
	aux[0] = (1 - prop) * (1 - prop * 0.5);
	aux[1] = pow(prop, 1.5);
	color.channel[0] = 0;
	color.channel[(0 + param->color) % 3 + 1] = \
		(uint8_t)(10 * (1 - prop) * aux[1] * 255);
	color.channel[(1 + param->color) % 3 + 1] = \
		(uint8_t)(20 * aux[0] * aux[1] * 255);
	color.channel[(2 + param->color) % 3 + 1] = \
		(uint8_t)(15 * aux[0] * aux[1] * 255);
	return (color);
}

static void	put_pixel(t_param *param, int x, int y, t_color color)
{
	int	offset;

	offset = (y * param->img_ptr->line_length + x \
				* (param->img_ptr->bits_per_pixel / 8));
	param->img_ptr->addr[offset] = color.channel[3];
	param->img_ptr->addr[++offset] = color.channel[2];
	param->img_ptr->addr[++offset] = color.channel[1];
	param->img_ptr->addr[++offset] = color.channel[0];
}

void	draw_fractal(t_param *param)
{
	int		x;
	int		y;
	t_color	color;

	y = HEIGHT;
	param->factor = complex_calc(
			(param->max.re - param->min.re) / (WIDTH - 1),
			(param->max.im - param->min.im) / (HEIGHT - 1));
	while (y > 0)
	{
		param->c.im = param->max.im - y * param->factor.re;
		x = 0;
		while (x < WIDTH)
		{
			param->c.re = param->min.re + x * param->factor.re;
			color = get_color(param->formula(param), param);
			put_pixel(param, x++, HEIGHT - y, color);
		}
		y--;
	}
	final_draw(param);
}

void	final_draw(t_param *param)
{
	if (!param->f_help)
	{
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, \
						param->img_ptr->img, 0, 0);
		mlx_string_put(param->mlx_ptr, param->win_ptr, 15, 15, \
						C_YELLOW, "CONTROLS:");
		mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 50, \
						C_YELLOW, "Show/hide help:  H");
		mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 75, \
						C_YELLOW, "Move:            left/rigth/up/down");
		mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 100, \
						C_YELLOW, "Shift colors:    C");
		mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 125, \
						C_YELLOW, "Change # iter.:  +/-");
		mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 150, \
						C_YELLOW, "Reset values:    R");
	}
	else
	{
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, \
				param->img_ptr->img, 0, 0);
	}
}
