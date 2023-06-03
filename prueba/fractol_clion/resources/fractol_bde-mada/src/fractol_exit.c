/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:58:48 by bde-mada          #+#    #+#             */
/*   Updated: 2023/04/27 20:09:24 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	parameter_menu(void)
{
	ft_printf("Input should be as follows:\n");
	ft_printf(ACCENT"\t./fractol <fractal> [Julia_re Julia_im]\n\n"NONE);
	ft_printf("*Julia params are in double format (e.g. 0.7 -0.253)\n");
	ft_printf("\tValues ranging -1 to 100 with max. 4 decimals\n\n");
	ft_printf("Available fractals:\n");
	ft_printf("\tMandelbrot\n");
	ft_printf("\tJulia\n");
	ft_printf("\tMandelbar\n");
	ft_printf("\tBurning_ship\n");
	exit(EXIT_FAILURE);
}

void	free_alloc(t_param *param)
{
	if (param->img_ptr)
		mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	if (param->tmp_img)
		mlx_destroy_image(param->mlx_ptr, param->tmp_img);
	if (param->win_ptr)
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	if (param->mlx_ptr)
		free(param->mlx_ptr);
	if (param->name)
		free(param->name);
	if (param->curr_iter)
		free(param->curr_iter);
	if (param)
		free(param);
}

int	exit_hook(t_param *param)
{
	errors_exit(0, param);
	return (1);
}

void	errors_exit(int error_id, t_param *param)
{
	if (param)
		free_alloc(param);
	if (error_id == 22)
		errno = 22;
	if (error_id == 83)
		errno = 83;
	if (error_id == 0)
		exit(EXIT_SUCCESS);
	perror("Fract'ol");
	if (error_id == 22)
		parameter_menu();
	if (param)
		free_alloc(param);
	exit(EXIT_FAILURE);
}
	//ft_printf("I'm in %s, line %d, file %s\n", __func__, __LINE__, __FILE__);
	//system("leaks fractol");
