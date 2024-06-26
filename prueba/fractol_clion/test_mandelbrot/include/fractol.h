/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:47:23 by danlopez          #+#    #+#             */
/*   Updated: 2023/10/26 20:01:26 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# if defined(__APPLE__)
#  include "key_macos.h"
#  include "minilibx_opengl_20191021/mlx.h"
# else
#  include "key_linux.h"
#  include "minilibx-linux/mlx.h"
# endif

# include "libft/libft.h"
//# include "minilibx-linux/mlx.h"
//# include "minilibx_opengl_20191021/mlx.h"
//# include "minilibx_mms_20191025_beta/mlx.h"

# include <stdlib.h>
# include <stdio.h>
# include  <errno.h>  // don't know if it's allowed --------------------------------
# include <math.h>
// To use uint8_t   //repensar si necesario ----------------------------------------
# include <stdint.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_color
{
	uint8_t	channel[4];
}	t_color;

typedef struct s_vars
{
	int		argc;
	char	**argv;
	char	*name;
	void	*mlx;
	void	*win;
	t_image	*img;
	int		color;
	int		max;
	double	zoom;
	int		offset_x;
	int		offset_y;
	int		julia;
	double	j_re;
	double	j_im;
}	t_vars;

//julia.c
void		ft_julia(void);
int			ft_check_julia(double c_x, double c_y, t_vars *vars);

//mandelbrot.c
void		ft_mandelbrot(void);
int			ft_check_mandelbrot(double c_x, double c_y, int max);

//complex.c
t_complex	ft_z(double re, double im);

//draw.c
void		ft_draw(t_vars *vars);

//draw_utils.c
t_image		*ft_init_image(t_vars *vars);

//controls.c
int			ft_key_press(int key, t_vars *vars);
int			ft_mouse_press(int key, int pos_x, int pos_y, t_vars *vars);

//fractol_exit.c
int			ft_exit(t_vars *vars);
void		ft_free_alloc(t_vars *vars);
void		ft_errors_exit(int error_id, t_vars *vars);


#endif
