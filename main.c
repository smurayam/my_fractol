/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 21:54:33 by nnnya             #+#    #+#             */
/*   Updated: 2026/01/09 22:09:55 by nnnya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main.c */
#include "includes/fractol.h"

/*
** 画像の特定座標(x, y)に色(color)を置く関数
** img.addr は char* 型なので、ポインタ演算で目的の位置へ移動し、
** unsigned int* にキャストして色情報を書き込む。
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

/*
** グラデーションを描画するテスト関数
** x座標に応じて赤成分、y座標に応じて緑成分を変化させる
*/
void	render_test_gradient(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			// 色の形式: 0x00RRGGBB
			// 赤(R): (x * 255 / 800) -> 0~255
			// 緑(G): (y * 255 / 800) -> 0~255
			my_mlx_pixel_put(data, x, y, ((x * 255 / 800) << 16) | ((y * 255
						/ 800) << 8));
			x++;
		}
		y++;
	}
}

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

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 800, "fract-ol");
	if (data.win_ptr == NULL)
	{
		free(data.mlx_ptr); // data.win_ptrが失敗した場合のケア
		return (1);
	}
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, 800, 800);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
			&data.img.line_len, &data.img.endian);

	// ここで描画処理を呼び出す
	render_test_gradient(&data);

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 17, 0, handle_close, &data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}