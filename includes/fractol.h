/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 21:54:04 by nnnya             #+#    #+#             */
/*   Updated: 2026/01/20 20:28:22 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../includes/Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

# define K_ESC 65307
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define PSYCHEDELIC_PURPLE 0x990099

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
	char	*name;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	julia_cx;
	double	julia_cy;
}			t_data;

void		data_init(t_data *data);
void		render(t_data *data);
int			handle_keypress(int keysym, t_data *data);
int			handle_mouse(int button, int x, int y, t_data *data);
int			handle_close(t_data *data);
double		ft_atof(char *s);

#endif