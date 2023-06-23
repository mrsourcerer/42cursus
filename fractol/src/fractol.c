/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:14:55 by danlopez          #+#    #+#             */
/*   Updated: 2023/06/23 07:20:58 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_args_ok(int argc, char *argv[])
{
	int	bad_args;

	bad_args = 0;
	if (argc == 1)
		bad_args = 1;
	if (argc == 2)
		if (ft_strlen(ft_strnstr(argv[1], "mandelbrot", 10)) == 10 || \
			ft_strlen(ft_strnstr(argv[1], "julia", 5)) == 5)
			bad_args = 1;
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
