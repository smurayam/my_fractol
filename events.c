/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:21:32 by smurayam          #+#    #+#             */
/*   Updated: 2026/01/20 20:30:47 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	data_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fractol");
	if (!data->win_ptr)
		exit(1);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	mlx_hook(data->win_ptr, 17, 0, handle_close, data);
	mlx_key_hook(data->win_ptr, handle_keypress, data);
	mlx_mouse_hook(data->win_ptr, handle_mouse, data);
}

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == K_ESC)
		handle_close(data);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	zoom_factor;
	double	center_r;
	double	center_i;

	(void)x;
	(void)y;
	zoom_factor = 1.0;
	if (button == MOUSE_WHEEL_UP)
		zoom_factor = 0.9;
	else if (button == MOUSE_WHEEL_DOWN)
		zoom_factor = 1.1;
	else
		return (0);
	center_r = (data->max_r - data->min_r) / 2 + data->min_r;
	center_i = (data->max_i - data->min_i) / 2 + data->min_i;
	data->min_r = (data->min_r - center_r) * zoom_factor + center_r;
	data->max_r = (data->max_r - center_r) * zoom_factor + center_r;
	data->min_i = (data->min_i - center_i) * zoom_factor + center_i;
	data->max_i = (data->max_i - center_i) * zoom_factor + center_i;
	render(data);
	return (0);
}
