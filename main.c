/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 21:54:33 by nnnya             #+#    #+#             */
/*   Updated: 2026/01/09 21:54:37 by nnnya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main.c */
#include "fractol.h"

/*
** イベントフック用関数
** ESCキーが押されたら終了する
*/
int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == K_ESC)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

/*
** ウィンドウの×ボタンが押されたら終了する
*/
int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

/*
** 初期化とウィンドウ生成、ループ開始
*/
int	main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 800, "fract-ol");
	if (data.win_ptr == NULL)
	{
		free(data.mlx_ptr);
		return (1);
	}
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, 800, 800);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 17, 0, handle_close, &data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}