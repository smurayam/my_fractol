/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 21:54:33 by nnnya             #+#    #+#             */
/*   Updated: 2026/01/18 00:23:11 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main.c */
#include "includes/fractol.h"

/*
** ピクセル描画ヘルパー
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

/*
** 座標のスケーリング
** (unscaled_num - min_old) / (max_old - min_old) * (max_new - min_new)
	+ min_new
** 今回は 0~WIDTH を min_r~max_r に変換
*/
double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num / old_max) + new_min);
}

/*
** マンデルブロ集合の計算と描画
** Z = Z^2 + C
*/
void	calculate_mandelbrot(t_data *data)
{
	int		x;
	int		y;
	int		i;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	double	tmp_zr;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// 1. 画面座標を複素平面座標に変換 (C)
			c_r = map(x, data->min_r, data->max_r, WIDTH);
			c_i = map(y, data->min_i, data->max_i, HEIGHT);
			// 2. Zの初期化
			z_r = 0.0;
			z_i = 0.0;
			// 3. 発散判定ループ
			i = 0;
			while (i < MAX_ITER)
			{
				// Z^2 + C の計算
				// 実部: x^2 - y^2 + a
				tmp_zr = z_r * z_r - z_i * z_i + c_r;
				// 虚部: 2xy + b
				z_i = 2 * z_r * z_i + c_i;
				z_r = tmp_zr;
				// 発散判定 (距離の2乗 > 4)
				if ((z_r * z_r + z_i * z_i) > 4.0)
					break ;
				i++;
			}
			// 4. 色付け (とりあえず白黒)
			if (i == MAX_ITER)
				my_mlx_pixel_put(data, x, y, BLACK); // 集合内
			else
				my_mlx_pixel_put(data, x, y, WHITE); // 発散
			x++;
		}
		y++;
	}
}

/*
** 初期化処理（表示範囲の設定など）
*/
void	data_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		exit(1);
	}
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	// マンデルブロ集合がきれいに見える初期範囲
	data->min_r = -2.0;
	data->max_r = 0.47;
	data->min_i = -1.12;
	data->max_i = 1.12; // 縦横比を合わせるため調整
}

/* その他のハンドラ関数はそのまま */
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
	t_data	data;

	data_init(&data);
	calculate_mandelbrot(&data); // 計算実行
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 17, 0, handle_close, &data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
