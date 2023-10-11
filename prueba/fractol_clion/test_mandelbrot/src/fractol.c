/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:14:55 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/11 07:14:17 by danlopez         ###   ########.fr       */
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
	mlx_hook(vars->win, 17, 0, ft_exit_hook, vars);
	mlx_hook(vars->win, 2, 0, key_press, vars);
	//mlx_hook(vars->win, 4, 0, mouse_press_hook, vars);
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
