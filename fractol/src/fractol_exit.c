/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 08:05:57 by danlopez          #+#    #+#             */
/*   Updated: 2024/01/11 19:35:52 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_free_alloc(t_vars *vars)
{
	ft_printf("exiting... in %s, line %d, file %s\n", __func__, __LINE__, __FILE__);
	if (vars->img)
		free(vars->img->img);
	ft_printf("exiting... in %s, line %d, file %s\n", __func__, __LINE__, __FILE__);
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img); //works in 42 not at home linux
	ft_printf("exiting... in %s, line %d, file %s\n", __func__, __LINE__, __FILE__);
	if (vars->img)
	{
		ft_printf("vars->img %p\n", vars->img);
		//next line:  pointer being freed was not allocated
		//free(vars->img);
	}
	ft_printf("exiting... in %s, line %d, file %s\n", __func__, __LINE__, __FILE__);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	ft_printf("exiting... in %s, line %d, file %s\n", __func__, __LINE__, __FILE__);
	if (vars->win)
	{
		ft_printf("vars->win %p\n", vars->win);
		//next line:  pointer being freed was not allocated
		//free(vars->win);
	}
	ft_printf("exiting... in %s, line %d, file %s\n", __func__, __LINE__, __FILE__);
	if (vars->mlx)
		free(vars->mlx);
	ft_printf("exiting... in %s, line %d, file %s\n", __func__, __LINE__, __FILE__);
	if (vars->name)
		free(vars->name);
	ft_printf("exiting... in %s, line %d, file %s\n", __func__, __LINE__, __FILE__);
	if (vars != NULL)
		free(vars);
}

void	ft_print_usage(void)
{
	ft_printf("Usage: \n");
	ft_printf("fractol mandelbrot\n");
	ft_printf("         or              \n");
	ft_printf("fractol julia num1 num2\n");
	ft_printf("\n (num1-> real part up to 4 decimal rounded)\n");
	ft_printf(" (num2-> imaginary part up to 4 decimal rounded)\n");
}

void	ft_errors_exit(int error_id, t_vars *vars)
{
	if (vars)
		ft_free_alloc(vars);
	if (error_id == 22)
		errno = 22;
	if (error_id == 6)
		errno = 6;
	if (error_id == 0)
	{
		//system("leaks fractol");  //----------------------------------------------------------------------
		exit(EXIT_SUCCESS);
	}
	if (error_id == 22)
		ft_print_usage();
	//if (vars)
	//	ft_free_alloc(vars);
	//system("leaks fractol");  //---------------------------------------------------------------------------
	exit(EXIT_FAILURE);
}

int	ft_exit(t_vars *vars)
{
	ft_errors_exit(0, vars);
	return (1);
}
