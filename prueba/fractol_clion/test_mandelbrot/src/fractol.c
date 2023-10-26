/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:14:55 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/26 20:17:14 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_args_ok(int argc, char *argv[])
{
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot"))
	{
		ft_mandelbrot();
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia"))
	{
		ft_julia();
	}
	else
	{
		ft_printf("Usage: fractol mandelbrot or fractol julia num1 num2\n");
		return (0);
	}
	return (1);
}

void	ft_init_vars(int argc, char **argv, t_vars *vars)
{
	vars->argc = argc;
	vars->argv = argv;
	vars->name = ft_strjoin("Fract'ol: ", argv[1]);
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
	if (ft_strcmp(argv[1], "julia"))
	{
		vars->j_re = ft_atof(argv[2]);
		vars->j_im = ft_atof(argv[3]);
	}
	mlx_hook(vars->win, 17, 1L << 17, ft_exit, vars);
	mlx_hook(vars->win, 2, 1L << 0, ft_key_press, vars);
	//mlx_hook(vars->win, 4, 1L << 12, ft_mouse_press, vars);
	mlx_mouse_hook(vars->win, ft_mouse_press, vars);
}

int	main(int argc, char *argv[])
{
	t_vars	*vars;

	if (!ft_args_ok(argc, argv))
		return (-1);
	vars = (t_vars *)malloc(sizeof(t_vars) * 1);
	if (!vars)
		return (-1); // gestionar errores *********************************************************
	ft_init_vars(argc, argv, vars);
	ft_draw(vars);
	mlx_loop(vars->mlx);
	ft_free_alloc(vars);
	return (0);
}
