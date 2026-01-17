/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 21:54:04 by nnnya             #+#    #+#             */
/*   Updated: 2026/01/18 00:21:37 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* fractol.h */
#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define K_ESC 65307
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

/* 色の定義（例） */
# define BLACK 0x000000
# define WHITE 0xFFFFFF

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	/* フラクタル描画範囲 */
	double min_r; // 実部の最小値 (左端)
	double max_r; // 実部の最大値 (右端)
	double min_i; // 虚部の最小値 (上端)
	double max_i; // 虚部の最大値 (下端)
}			t_data;

#endif