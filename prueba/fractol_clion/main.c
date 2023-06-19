/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:25:21 by danlopez          #+#    #+#             */
/*   Updated: 2023/06/19 07:17:56 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minilibx_mms_20191025_beta/mlx.h"
#include <stdio.h>
#include <stdlib.h>  

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

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_hook(vars.win, 2, 0, key_press, &vars);
	mlx_hook(vars.win, 17, 0, close, &vars);
	mlx_loop(vars.mlx);
}
