/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:25:21 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/29 12:01:04 by danlopez         ###   ########.fr       */
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

/*
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
*/

/*#include <mlx.h>

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;
*/

int	main(int argc, char **argv)
{
	int		i;
	double	f;
	char	*str;
	char	*str2;
	
	if (argc != 2)
		return (0);
	i = (int)-1.1416;
	f = -0.1416;
	str = ft_strdup("0.1416");
	str2 = ft_strdup("-0.1416");
	ft_printf("prueba printf %i %i %f %f\n", i, -i, f, -f);
	ft_printf("prueba con atof %s --> %f\n", str, ft_atof(str));
	ft_printf("prueba con atof %s --> %f\n", str2, ft_atof(str2));
	ft_printf("prueba desde argv con atof %s --> %f\n", argv[1], ft_atof(argv[1]));
}

