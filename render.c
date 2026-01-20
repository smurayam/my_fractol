/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:21:55 by smurayam          #+#    #+#             */
/*   Updated: 2026/01/20 20:22:00 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* render.c */
#include "includes/fractol.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

// 座標変換マップ関数
static double	map(double unscaled, double new_min, double new_max,
		double old_max)
{
	return ((new_max - new_min) * (unscaled / old_max) + new_min);
}

// 複素数の計算と発散判定
static void	calculate_pixel(t_data *data, int x, int y)
{
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	double	tmp;
	int		iter;

	// マンデルブロとジュリアで初期値が異なる
	if (ft_strncmp(data->name, "julia", 5) == 0)
	{
		z_r = map(x, data->min_r, data->max_r, WIDTH);
		z_i = map(y, data->min_i, data->max_i, HEIGHT);
		c_r = data->julia_cx;
		c_i = data->julia_cy;
	}
	else // mandelbrot
	{
		z_r = 0.0;
		z_i = 0.0;
		c_r = map(x, data->min_r, data->max_r, WIDTH);
		c_i = map(y, data->min_i, data->max_i, HEIGHT);
	}
	iter = 0;
	while (iter < MAX_ITER)
	{
		if ((z_r * z_r + z_i * z_i) > 4.0)
			break ;
		tmp = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_r * z_i + c_i;
		z_r = tmp;
		iter++;
	}
	// 色付け: 反復回数に応じて色を変える (必須要件)
	if (iter == MAX_ITER)
		my_mlx_pixel_put(data, x, y, BLACK);
	else
		// 例: サイケデリックな色計算
		my_mlx_pixel_put(data, x, y, (iter * PSYCHEDELIC_PURPLE));
}

void	render(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calculate_pixel(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0,
		0);
}