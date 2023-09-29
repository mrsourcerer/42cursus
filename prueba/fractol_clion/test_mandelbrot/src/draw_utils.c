/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 06:33:44 by danlopez          #+#    #+#             */
/*   Updated: 2023/09/29 06:44:16 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_image	*ft_init_image(t_vars *vars)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image) * 1);
	if (!img)
		return (NULL); // gestionar errores *******************************************
	img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!img)
		return (NULL); // gestionar errores *******************************************
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
				&(img->line_length), &(img->endian));
	return (img);
}
