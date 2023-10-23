/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 07:06:00 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/23 06:51:42 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_key_press(int key, t_vars *vars)
{
	ft_printf("pressed: %i\n", key);
	if (key == K_ESC || key == K_Q)
	{
		ft_errors_exit(0, vars);
	}
	if (key == K_Z)
		vars->max = vars->max + 1;
	if (key == K_X)
		vars->max = vars->max - 1;
	ft_draw(vars);
	return (0);
}

void	ft_reset_zoom(t_vars *vars)
{
	vars->zoom = 1.0;
	vars->offset_x = WIDTH / 2;
	vars->offset_y = HEIGHT / 2;
	vars->max = 20;
}

int	ft_mouse_press(int key, int pos_x, int pos_y, t_vars *vars)
{
	char	*name;
	double	old_zoom;

	old_zoom = vars->zoom;
	name = vars->name;
	if ((key == M_SCR_U || key == M_CLK_L) && (vars->zoom <= 2048))
	{
		vars->zoom = vars->zoom * 1.5;
		vars->max = vars->max + 1;
		//vars->max = vars->max + (int)(vars->zoom * 0.01);
	}
	if (key == M_SCR_D || key == M_CLK_R)
	{
		vars->zoom = vars->zoom / 1.5;
		vars->max = vars->max - 1;
		//vars->max = vars->max - (int)(old_zoom * 0.01);
		ft_printf("reduccion zoom: old_zoom: %f -> zoom: %f\n", old_zoom, vars->zoom);
		//old_zoom = vars->zoom;
	}
	vars->offset_x = pos_x + (vars->offset_x - WIDTH / 2) * vars->zoom / old_zoom;
	vars->offset_y = pos_y + (vars->offset_y - HEIGHT / 2) * vars->zoom / old_zoom;
	if (vars->zoom <= 1.0)
		ft_reset_zoom(vars);
	ft_printf("%s pressed: mouse %i  pos_x: %i  pos_y: %i  zoom: %f\n", name, key, pos_x, pos_y, vars->zoom);
	ft_draw(vars);
	return (0);
}
