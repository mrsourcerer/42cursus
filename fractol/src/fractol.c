/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:14:55 by danlopez          #+#    #+#             */
/*   Updated: 2023/09/18 06:25:36 by danlopez         ###   ########.fr       */
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
		if (!ft_strcmp(argv[1], "mandelbrot"))
			bad_args = 1;
	if (argc == 4)
	{
		ft_printf("argc 3: %f\n", ft_atof(argv[2]));
		ft_printf("argc 4: %f\n", ft_atof(argv[3]));
		if (!ft_strcmp(argv[1], "julia"))
			bad_args = 1;
	}
	if (bad_args)
	{
		ft_printf("Usage: fractol mandelbrot or fractol julia\n");
		return (1);
	}
	ft_printf("args ok\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	if (!ft_args_ok(argc, argv))
		return (-1);
	return (0);
}
