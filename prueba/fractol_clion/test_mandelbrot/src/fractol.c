/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:14:55 by danlopez          #+#    #+#             */
/*   Updated: 2023/09/21 07:24:12 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_args_ok(int argc, char *argv[])
{
	int	bad_args;

	bad_args = 0;
	if (argc < 2 || argc == 3 || argc > 4)
		bad_args = 1;
	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "mandelbrot"))
			bad_args = 1;
		ft_mandelbrot();
	}
	if (argc == 4)
	{
		//ft_printf("argc 3: %f\n", ft_atof(argv[2])); ******************************************
		//ft_printf("argc 4: %f\n", ft_atof(argv[3])); ******************************************
		if (!ft_strcmp(argv[1], "julia"))
			bad_args = 1;
		ft_julia();
	}
	if (bad_args)
	{
		ft_printf("Usage: fractol mandelbrot or fractol julia num1 num2\n");
		return (1);
	}
	return (0);
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
	return (0);
}
