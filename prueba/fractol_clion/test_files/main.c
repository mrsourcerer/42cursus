/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:25:21 by danlopez          #+#    #+#             */
/*   Updated: 2023/06/21 06:57:55 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"
//#include "include/minilibx_mms_20191025_beta/mlx.h"
//#include <stdio.h>
//#include <stdlib.h>  

/*typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;*/

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	system("leaks fractol");
	exit (0);
}

int ft_key_press(int key, void *param)
{
	ft_printf("key_press: %i\n", key);
	if (key == K_Q || key == K_ESC)
		ft_close(param);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_hook(vars.win, 2, 1L<<0, ft_key_press, &vars);
	mlx_loop(vars.mlx);
}
