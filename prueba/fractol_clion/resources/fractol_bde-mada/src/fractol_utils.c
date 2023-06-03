/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:13:09 by bde-mada          #+#    #+#             */
/*   Updated: 2023/04/25 19:20:01 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_default(t_param *param, int mode)
{
	ft_printf("Setting defaults\n");
	if (mode == 0)
	{
		param->mlx_ptr = NULL;
		param->win_ptr = NULL;
		param->img_ptr = NULL;
		param->tmp_img = NULL;
		param->name = NULL;
		param->curr_iter = NULL;
	}
	param->max_iter = 50;
	param->min = complex_calc(-2.0, -2.0);
	param->max.re = 2.0;
	param->max.im = param->min.im \
				+ (param->max.re - param->min.re) * HEIGHT / WIDTH;
	param->k = complex_calc(-0.4, -0.2);
	param->f_fixed_julia = 0;
	param->f_help = 0;
	param->color = 0;
}

t_image	*init_image(t_param *param)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		errors_exit(22, param);
	img->img = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	if (!img)
		errors_exit(80, param);
	img->addr = mlx_get_data_addr(img->img, \
								&(img->bits_per_pixel), \
								&(img->line_length), \
								&(img->endian));
	return (img);
}
