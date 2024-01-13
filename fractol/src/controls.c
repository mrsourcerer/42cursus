/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 08:05:46 by danlopez          #+#    #+#             */
/*   Updated: 2023/12/21 19:45:52 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_key_press(int key, t_vars *vars)
{
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
	double	old_zoom;

	old_zoom = vars->zoom;
	if ((key == M_SCR_U || key == M_CLK_L) && (vars->zoom <= 2048))
	{
		vars->zoom = vars->zoom * 1.5;
		vars->max = vars->max + 1;
	}
	if (key == M_SCR_D || key == M_CLK_R)
	{
		vars->zoom = vars->zoom / 1.5;
		vars->max = vars->max - 1;
	}
	vars->offset_x = pos_x + (vars->offset_x - WIDTH / 2) \
						* vars->zoom / old_zoom;
	vars->offset_y = pos_y + (vars->offset_y - HEIGHT / 2) \
						* vars->zoom / old_zoom;
	if (vars->zoom <= 1.0)
		ft_reset_zoom(vars);
	ft_draw(vars);
	return (0);
}
