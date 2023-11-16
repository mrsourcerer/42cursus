/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:14:55 by danlopez          #+#    #+#             */
/*   Updated: 2023/11/16 21:07:35 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_args_ok(t_vars *vars)
{
	if (vars->argc == 2 && ft_strcmp(vars->argv[1], "mandelbrot"))
	{
		vars->j_re = 0;
		vars->j_im = 0;
		ft_mandelbrot(vars);
	}
	else if (ft_julia_ok(vars))
	{
		ft_julia(vars);
	}
	else
	{
		ft_printf("Usage: fractol mandelbrot or fractol julia num1 num2\n");
		return (0);
	}
	return (1);
}

void	ft_init_vars(t_vars *vars)
{
	vars->name = ft_strjoin("Fract'ol: ", vars->argv[1]);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return ; // gestionar errores *************************************************************
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, vars->name);
	if (!vars->win)
		return ; // gestionar errores *************************************************************
	vars->img = ft_init_image(vars);
	vars->color = 0;
	vars->max = 20;
	vars->zoom = 1.0;
	vars->offset_x = WIDTH / 2;
	vars->offset_y = HEIGHT / 2;
	mlx_hook(vars->win, 17, 1L << 17, ft_exit, vars);
	mlx_hook(vars->win, 2, 1L << 0, ft_key_press, vars);
	mlx_mouse_hook(vars->win, ft_mouse_press, vars);
}

int	main(int argc, char *argv[])
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars) * 1);
	if (!vars)
		return (-1); // gestionar errores *********************************************************
	vars->argc = argc;
	vars->argv = argv;
	if (!ft_args_ok(vars))
		return (free(vars), -1);
	ft_init_vars(vars);
	ft_draw(vars);
	mlx_loop(vars->mlx);
	ft_free_alloc(vars);
	return (0);
}
