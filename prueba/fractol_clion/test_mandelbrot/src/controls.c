/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 07:06:00 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/13 13:33:34 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_key_press(int key, t_vars *vars)
{
	if (key == K_ESC || key == K_Q)
	{
		ft_printf("pressed: %i\n", key);
		ft_errors_exit(0, vars);
	}
	return (0);
}

int	ft_mouse_press(int key, int pos_x, int pos_y, t_vars *vars)
{
	char	*name;
	double	old_zoom;

	old_zoom = vars->zoom;
	name = vars->name;
	ft_printf("llega\n");
	if (key == M_SCR_U)
	{
		vars->zoom = vars->zoom * 1.2;
		vars->max = vars->max + (int)vars->zoom * 0;
	}
	if (key == M_SCR_D)
	{
		vars->zoom = vars->zoom / 1.2;
		vars->max = vars->max - (int)vars->zoom * 0;
	}
	if (pos_x < WIDTH / 2)
		vars->offset_x = 2 * ((2 / old_zoom) - (2 / vars->zoom));
	else if (pos_x > WIDTH / 2)
		vars->offset_x = 2 * (- (2 / old_zoom) + (2 / vars->zoom));
	if (pos_y < HEIGHT / 2)
		vars->offset_y = 2 * ((2 / old_zoom) - (2 / vars->zoom));
	else if (pos_y > HEIGHT / 2)
		vars->offset_y = 2 * (- (2 / old_zoom) + (2 / vars->zoom));
	if (vars->zoom <= 1.0)
	{
		vars->zoom = 1.0;
		vars->offset_x = 0;
		vars->offset_y = 0;
		vars->max = 15;
	}
	ft_printf("%s pressed: M_SCR_U %i  pos_x: %i  pos_y: %i  zoom: %f\n", name, key, pos_x, pos_y, vars->zoom);
	ft_draw(vars);
	return (0);
}
