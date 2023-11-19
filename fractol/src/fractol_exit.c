/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 08:05:57 by danlopez          #+#    #+#             */
/*   Updated: 2023/11/19 11:29:26 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_free_alloc(t_vars *vars)
{
	ft_printf("Llega ft_free_alloc\n");
	//if (vars->img->addr)
	//	free(vars->img->addr);
	//ft_printf("Pasa free(vars->img->addr\n");
	if (vars->img)
	{
		free(vars->img->img);
	}
	ft_printf("Pasa free(vars->img->img\n");
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	ft_printf("Pasa mlx_destroy_image\n");
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	ft_printf("Pasa mlx_destroy_window\n");
	if (vars->mlx)
		free(vars->mlx);
	ft_printf("Pasa free(vars->mlx)\n");
	if (vars->name)
		free(vars->name);
	ft_printf("Pasa free(vars->name)\n");
	//free(vars->argv);
	//ft_printf("Pasa free(vars->argv)\n");
	/*if (vars)
	{
		ft_printf("Entra a liberar free(vars)\n");
		free(vars);
	}
	*/
	//free(vars);
	ft_printf("Pasa free(vars)\n");
}

void	ft_print_usage(void)
{
	ft_printf("Usage: \n");
	ft_printf("fractol mandelbrot\n");
	ft_printf("         or              \n");
	ft_printf("fractol julia num1 num2\n");
	ft_printf("\n (num1-> real part up to 4 decimal)\n");
	ft_printf(" (num2-> imaginary part up to 4 decimal)\n");
}

void	ft_errors_exit(int error_id, t_vars *vars)
{
	ft_printf("Llega ft_errors_exit\n");
	if (vars)
		ft_free_alloc(vars);
	if (error_id == 22)
		errno = 22;
	if (error_id == 6)
		errno = 6;
	if (error_id == 0)
	{
		system("leaks --list -- fractol");
		exit(EXIT_SUCCESS);
	}
	if (error_id == 22)
		ft_print_usage();
	//if (vars)
	//	ft_free_alloc(vars);
	system("leaks fractol");
	exit(EXIT_FAILURE);
}

int	ft_exit(t_vars *vars)
{
	ft_printf("Llega ft_exit\n");
	ft_errors_exit(0, vars);
	return (1);
}
