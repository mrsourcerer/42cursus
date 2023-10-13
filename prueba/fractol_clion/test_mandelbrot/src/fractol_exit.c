/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 06:41:16 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/13 08:37:03 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_free_alloc(t_vars *vars)
{
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		free(vars->mlx);
	if (vars->name)
		free(vars->name);
	if (vars)
		free(vars);
}

int	ft_exit(t_vars *vars)
{
	ft_errors_exit(0, vars);
	return (1);
}

void	ft_errors_exit(int error_id, t_vars *vars)
{
	if (vars)
		ft_free_alloc(vars);
	if (error_id == 0)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
