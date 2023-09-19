/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:47:23 by danlopez          #+#    #+#             */
/*   Updated: 2023/09/19 07:14:35 by danlopez         ###   ########.fr       */
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

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

/*typedef	struct s_complex
{
	double	re;
	double	im;
}	t_complex;*/

typedef struct s_vars
{
	void	*mlx;
	void	*win;
//	t_image	*buf1;
//	t_image	*buf2;
}	t_vars;

void	ft_julia(void);
void	ft_mandelbrot(void);

#endif
