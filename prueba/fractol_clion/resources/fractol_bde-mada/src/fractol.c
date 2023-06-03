/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:04:30 by bde-mada          #+#    #+#             */
/*   Updated: 2023/04/28 11:47:45 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_param(char *str, t_param *param)
{
	int	i;
	int	decimal[2];

	i = 0;
	decimal[0] = 0;
	decimal[1] = 0;
	if (ft_strlen(str) > 8)
		errors_exit(22, param);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			errors_exit(22, param);
		if (str[i] == '.')
			decimal[0] = 1;
		i++;
		if (decimal[0] == 1)
			decimal[1]++;
		if (decimal[1] > 5)
			errors_exit(22, param);
	}
}

static void	julia_args(t_param *param)
{
	int			i;
	double		julia[2];

	i = 2;
	while (i < 4)
		check_param(param->argv[i++], param);
	julia[0] = ft_atof(param->argv[2]);
	julia[1] = ft_atof(param->argv[3]);
	if (julia[0] < -1 || julia[0] > 100 \
		|| julia[1] < -1 || julia[1] > 100)
		errors_exit(22, param);
	param->k = complex_calc(julia[0], julia[1]);
	param->f_fixed_julia = 1;
}

static int	(*get_formula(char *fractal)) (t_param *param)
{
	int	i;
	int	(*formula)(t_param *fractol);

	i = 0;
	formula = NULL;
	if (!ft_strcmp(fractal, "Mandelbrot"))
		formula = &calc_mandelbrot;
	else if (!ft_strcmp(fractal, "Julia"))
		formula = &calc_julia;
	else if (!ft_strcmp(fractal, "Mandelbar"))
		formula = &calc_mandelbar;
	else if (!ft_strcmp(fractal, "Burning_ship"))
		formula = &calc_burning_ship;
	else
		ft_printf("Fractal not found\n");
	return (formula);
}

static void	init_program(int argc, char **argv, t_param *param)
{	
	param->argc = argc;
	param->argv = argv;
	set_default(param, 0);
	param->name = ft_strjoin("Fract'ol: ", argv[1]);
	ft_printf("%s\n", param->name);
	param->mlx_ptr = mlx_init();
	if (!param->mlx_ptr)
		errors_exit(83, param);
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, param->name);
	if (!param->win_ptr)
		errors_exit(83, param);
	param->formula = get_formula(argv[1]);
	param->img_ptr = init_image(param);
	mlx_hook(param->win_ptr, 2, 0, key_press, param);
	mlx_hook(param->win_ptr, 4, 0, mouse_press_hook, param);
	mlx_hook(param->win_ptr, 17, 0, exit_hook, param);
}

int	main(int argc, char *argv[])
{
	t_param	*param;

	if (argc != 2 && argc != 4)
		errors_exit(22, NULL);
	if (!get_formula(argv[1]) || \
		((get_formula(argv[1]) != &calc_julia) && argc != 2))
		errors_exit(22, NULL);
	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		errors_exit(12, param);
	init_program(argc, argv, param);
	if (!ft_strcmp("Julia", param->name + 10) && argc == 4)
		julia_args(param);
	draw_fractal(param);
	mlx_loop(param->mlx_ptr);
	free_alloc(param);
	return (EXIT_SUCCESS);
}
