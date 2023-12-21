/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:14:55 by danlopez          #+#    #+#             */
/*   Updated: 2023/12/21 19:36:01 by danlopez         ###   ########.fr       */
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
		ft_errors_exit(22, vars);
	}
	return (1);
}

void	ft_init_vars(t_vars *vars)
{
	vars->name = ft_strjoin("Fract'ol: ", vars->argv[1]);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		ft_errors_exit(6, vars);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, vars->name);
	if (!vars->win)
		ft_errors_exit(6, vars);
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

void	ft_secure_vars(t_vars *vars)
{
	vars->name = NULL;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img = NULL;
}

int	main(int argc, char *argv[])
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars) * 1);
	if (!vars)
		return (-1);
	vars->argc = argc;
	vars->argv = argv;
	ft_secure_vars(vars);
	ft_args_ok(vars);
	ft_init_vars(vars);
	ft_draw(vars);
	mlx_loop(vars->mlx);
	// a partir de aqui sobra todo hasta el return
	/*free(vars);*/
	return (0);
}
