/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 07:03:21 by danlopez          #+#    #+#             */
/*   Updated: 2023/11/19 09:05:17 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_image	*ft_init_image(t_vars *vars)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image) * 1);
	if (!img)
		ft_errors_exit(6, vars);
	ft_printf("direccion img: %p\n", img); //
	img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!img->img)
		ft_errors_exit(6, vars);
	ft_printf("direccion img->img: %p\n", img->img); //
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
				&(img->line_length), &(img->endian));
	ft_printf("direccion img->addr: %p\n", img->addr); //
	return (img);
}

double	ft_get_cx(int x, t_vars *vars)
{
	double	c_x;
	double	zoom;
	double	z_x;

	zoom = vars->zoom;
	z_x = vars->offset_x;
	c_x = (x + z_x - WIDTH) * 4 / WIDTH / zoom;
	return (c_x);
}

double	ft_get_cy(int y, t_vars *vars)
{
	double	c_y;
	double	zoom;
	double	z_y;

	zoom = vars->zoom;
	z_y = vars->offset_y;
	c_y = (HEIGHT - (y + z_y)) * 4 / HEIGHT / zoom;
	return (c_y);
}

void	ft_channel(t_color *color, uint8_t c1, uint8_t c2, uint8_t c3)
{
	color->channel[1] = c1;
	color->channel[2] = c2;
	color->channel[3] = c3;
}
