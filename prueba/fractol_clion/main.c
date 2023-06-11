#include "include/fractol.h"

void	free_alloc(t_data *param)
{
	//if (param->img_ptr)
	//	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	//if (param->tmp_img)
	//	mlx_destroy_image(param->mlx_ptr, param->tmp_img);
	if (param->win_ptr)
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	if (param->mlx_ptr)
		free(param->mlx_ptr);
	//if (param->name)
	//	free(param->name);
	//if (param->curr_iter)
	//	free(param->curr_iter);
	//if (param)
	//	free(param);
}

void	errors_exit(int error_id, t_data *param)
{
	if (param)
		free_alloc(param);
	if (error_id == 22)
		errno = 22;
	if (error_id == 83)
		errno = 83;
	if (error_id == 0)
		exit(EXIT_SUCCESS);
	perror("fractol");
	if (error_id == 22)
		write(1, "parameter_menu function", 23);
		//parameter_menu();
	if (param)
		free_alloc(param);
	exit(EXIT_FAILURE);
}

int	exit_hook(t_data *param)
{
	errors_exit(0, param);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == MAINPAD_ESC || key == MAINPAD_Q)
		errors_exit(0, data);
	return (0);
}

int	main(void)
{
	t_data	*data;

	data = (t_data *)malloc(1 * sizeof(t_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 640, 360, "Tutorial Window - Create Image");
	
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 640/1.5, 360/1.5, 0xFFFFFF);

	mlx_hook(data->win_ptr, 2, 0, key_press, data);
	//mlx_hook(data->win_ptr, 17, 0, exit_hook, data); // when this line is present it makes segmentation fault... dunno why

	mlx_loop(data->mlx_ptr);

	//mlx_destroy_display(mlx);
	//if (data.win_ptr)
	//	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	//if (data.mlx_ptr)
	//	free(data.mlx_ptr);
	//if (data)
	//	free(data);
	free_alloc(data);
	return (0);
}
