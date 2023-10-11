/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 07:06:00 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/11 07:25:47 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_press(int key, t_vars *vars)
{
	if (key == K_ESC || key == K_Q)
	{
		ft_printf("pressed: %i", key);
		ft_errors_exit(0, vars);
	}
	return (0);
}
