/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:25:21 by danlopez          #+#    #+#             */
/*   Updated: 2023/06/19 20:30:37 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minilibx_mms_20191025_beta/mlx.h"
#include <stdio.h>
#include <stdlib.h>  

#define MLX_PTR 1 << 0
#define MLX_WIN 1 << 1
#define MLX_IMG 1 << 2

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

int key_press(int key, void *param)
{
	printf("key_press");
	(void)key;
	close(param);
	return (0);
}

void	mlx_free(char flags, t_vars *mlx)
{
	//if (flags & MLX_IMG)
	//	mlx_destroy_image(mlx->ptr, mlx->img);
	if (flags & MLX_WIN)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (flags & MLX_PTR)
		free(mlx->mlx);
	exit(0);
}

int	red_cross_hook(void *e_void)
{
	t_vars	*e;

	e = (t_vars *)e_void;
	//free_parsing(e);
	mlx_free(MLX_PTR | MLX_IMG | MLX_WIN, e->mlx);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_hook(vars.win, 17, 0, red_cross_hook, &vars);
	mlx_hook(vars.win, 2, 0, key_press, &vars);
	mlx_loop(vars.mlx);
}
