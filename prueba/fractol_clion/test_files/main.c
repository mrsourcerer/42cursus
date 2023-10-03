/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:25:21 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/03 07:16:43 by danlopez         ###   ########.fr       */
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

void my_pixel_put(t_image *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_image	img;

/*
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	mlx_pixel_put(mlx, mlx_win, 100, 100, 0x00FF0000);
	mlx_loop(mlx);
*/	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	img.img = mlx_new_image(mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//mlx_pixel_put(mlx, mlx_win, 100, 100, 0x00FF0000);
	my_pixel_put(&img, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);


/*	t_vars	vars;
	t_image	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");

	
	img.img = mlx_new_image(vars.mlx, 640, 480);
	
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_pixel_put(&img, 100, 100, 0x00FFFFFF);
	ft_pixel_put(&img, 99, 100, 0x00FFFFFF);
	ft_pixel_put(&img, 101, 100, 0x00FFFFFF);
	ft_pixel_put(&img, 100, 99, 0x00FFFFFF);
	ft_pixel_put(&img, 100, 101, 0x00FFFFFF);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_hook(vars.win, 2, 1L<<0, ft_key_press, &vars);
	mlx_loop(vars.mlx);*/
}
