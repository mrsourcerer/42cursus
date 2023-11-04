/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 08:05:57 by danlopez          #+#    #+#             */
/*   Updated: 2023/11/04 08:19:03 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_free_alloc(t_vars *vars)
{
	ft_printf("Llega ft_free_alloc\n");
	//if (vars->img)
	//	mlx_destroy_image(vars->mlx, vars->img);
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
	if (vars)
		free(vars);
	ft_printf("Pasa free(vars)\n");
}

void	ft_errors_exit(int error_id, t_vars *vars)
{
	ft_printf("Llega ft_errors_exit\n");
	if (vars)
		ft_free_alloc(vars);
	if (error_id == 0)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

int	ft_exit(t_vars *vars)
{
	ft_printf("Llega ft_exit\n");
	ft_errors_exit(0, vars);
	return (1);
}
