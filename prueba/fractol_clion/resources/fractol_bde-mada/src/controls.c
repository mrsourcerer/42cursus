/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:03:02 by bde-mada          #+#    #+#             */
/*   Updated: 2023/04/27 19:56:08 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_max_iter(int key, t_param *param)
{
	if (key == MAINPAD_PLUS || key == NUMPAD_PLUS)
	{
		param->max_iter = param->max_iter * 105 / 100;
		if (param->max_iter < 20)
			param->max_iter++;
	}
	else if (param->max_iter > 5)
		param->max_iter = param->max_iter * 95 / 100;
	else
		ft_printf("Min iter # reached\n");
	ft_printf("Current iter #: %d\n", param->max_iter);
	draw_fractal(param);
}

static void	move(int key, t_param *param)
{
	t_complex	delta;

	delta = complex_calc(fabs(param->max.re - param->min.re), \
							fabs(param->max.im - param->min.im));
	if (key == ARROW_LEFT)
	{
		param->min.re -= delta.re * 0.05;
		param->max.re -= delta.re * 0.05;
	}
	else if (key == ARROW_RIGHT)
	{
		param->min.re += delta.re * 0.05;
		param->max.re += delta.re * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		param->min.im += delta.im * 0.05;
		param->max.im += delta.im * 0.05;
	}
	else if (key == ARROW_UP)
	{
		param->min.im -= delta.im * 0.05;
		param->max.im -= delta.im * 0.05;
	}
	draw_fractal(param);
}

int	key_press(int key, t_param *param)
{
	if (key == MAINPAD_ESC || key == MAINPAD_Q)
		errors_exit(0, param);
	if (key == MAINPAD_H)
	{
		param->f_help = !param->f_help;
		final_draw(param);
	}
	if (key == MAINPAD_R)
	{
		set_default(param, 1);
		draw_fractal(param);
	}
	if (key == MAINPAD_C)
	{
		param->color = (param->color + 1) % 3;
		ft_printf("Color: %d\n", param->color + 1);
		draw_fractal(param);
	}
	if (key >= ARROW_LEFT && key <= ARROW_UP)
		move(key, param);
	if (key == NUMPAD_PLUS || key == NUMPAD_MINUS || key == MAINPAD_PLUS \
			|| key == MAINPAD_MINNUS)
		change_max_iter(key, param);
	return (0);
}

static void	set_julia_params(int pos_x, int pos_y, t_param *param)
{
	if (pos_x >= 0 && pos_x <= WIDTH && pos_y >= 0 && pos_y <= HEIGHT)
	{
		param->k.re = ((double)pos_x - 500) * 2 / 1000;
		param->k.im = ((double)pos_y - 500) * 2 / 1000;
	}
}

int	mouse_press_hook(int key, int pos_x, int pos_y, t_param *param)
{
	t_complex	pos;
	double		zoom;

	if (key == MOUSE_LEFT || key == MOUSE_RIGHT)
	{
		set_julia_params(pos_x, pos_y, param);
		draw_fractal(param);
		return (0);
	}
	else if (key == MOUSE_WHEEL_DOWN)
		zoom = 1.1;
	else
		zoom = 0.9;
	pos = complex_calc((double)pos_x / (WIDTH / (param->max.re \
				- param->min.re)) + param->min.re, (double)(HEIGHT - pos_y) \
				/ (HEIGHT / (param->max.im - param->min.im)) \
				* -1 + param->max.im);
	param->min.re = pos.re + (param->min.re - pos.re) * zoom;
	param->min.im = pos.im + (param->min.im - pos.im) * zoom;
	param->max.re = pos.re + (param->max.re - pos.re) * zoom;
	param->max.im = param->min.im \
				+ (param->max.re - param->min.re) * HEIGHT / WIDTH;
	draw_fractal(param);
	return (0);
}

/* int	mouse_move_hook(int pos_x, int pos_y, t_param *param)
{
	param->mouse_x = pos_x;
	param->mouse_y = pos_y;
	return (0);
	param = NULL;
} */
