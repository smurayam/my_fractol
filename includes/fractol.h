/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 21:54:04 by nnnya             #+#    #+#             */
/*   Updated: 2026/01/09 21:54:10 by nnnya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* fractol.h */
#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

/* キーコード (Linux/X11用) */
# define K_ESC 65307

/*
** mlx_ptr       : MLX接続識別子
** win_ptr       : ウィンドウ識別子
** img.img_ptr   : イメージ識別子
** img.addr      : ピクセルデータの開始アドレス
** img.bpp       : 1ピクセルあたりのビット数
** img.line_len  : 1行のバイト数
** img.endian    : エンディアン情報
*/
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
}			t_data;

#endif
