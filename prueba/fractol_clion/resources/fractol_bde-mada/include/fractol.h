/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:26:41 by bde-mada          #+#    #+#             */
/*   Updated: 2023/04/25 19:30:14 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "keys_macos.h"
# include "colors.h"
// To use uint8_t
# include <stdint.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_complex{
	double	re;
	double	im;
}				t_complex;

typedef struct s_color{
	uint8_t	channel[4];
}				t_color;

/*
# argv				- introduced argument list
# mlx_ptr			- mlx connection id
# win_ptr			— mlx window id
# img_ptr			— image info
# name				- name of the chosen fractal
# formula			- formula of the chosen fractal
# max_iter			— maximum iteration #
# min				— minimum real and imaginary parts of complex numbers
# max				— maximum real and imaginary parts of complex numbers
# factor			— ratio of complex numbers and pixels
# c					— complex number
# k					— constant complex number (only for Julia)
# mouse_x			- x coord of the mouse position
# mouse_y			- y coord of the mouse position
# f_julia_fixed		— flag that reports Julia is fixed or is not
# f_help			— flag to report of the help display
# color				— shift of color channels
*/

typedef struct s_param {
	int			argc;
	char		**argv;
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*img_ptr;
	t_image		*tmp_img;
	char		*name;
	char		*curr_iter;
	int			(*formula)(struct s_param *param);
	int			max_iter;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
	int			mouse_x;
	int			mouse_y;
	int			f_fixed_julia;
	int			f_help;
	int			color;
}				t_param;

//draw_fractal
void		draw_fractal(t_param *param);
void		final_draw(t_param *param);

//controls.c
int			key_press(int key, t_param *param);
int			mouse_press_hook(int button, int pos_x, int pos_y, t_param *param);

// fractals.c
t_complex	complex_calc(double re, double im);
int			calc_mandelbrot(t_param *param);
int			calc_julia(t_param *param);
int			calc_mandelbar(t_param *param);
int			calc_burning_ship(t_param *param);

//fractol_utils.c
double		ft_atof(const char *s);
void		set_default(t_param *param, int mode);
t_image		*init_image(t_param *param);

//fractol_exit.c
void		parameter_menu(void);
void		free_alloc(t_param *param);
int			exit_hook(t_param *param);
void		errors_exit(int error_id, t_param *param);

#endif
