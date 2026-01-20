/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 21:54:33 by nnnya             #+#    #+#             */
/*   Updated: 2026/01/20 20:31:23 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static void	print_error_and_exit(void)
{
	ft_putstr_fd("Usage: ./fractol mandelbrot\n", 1);
	ft_putstr_fd("       ./fractol julia <real> <i>\n", 1);
	exit(1);
}

double	ft_atof(char *s)
{
	double	val;
	double	power;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	val = 0.0;
	power = 1.0;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		val = 10.0 * val + (s[i++] - '0');
	if (s[i] == '.')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		val = 10.0 * val + (s[i++] - '0');
		power *= 10.0;
	}
	return (sign * val / power);
}

static void	parse_args(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		print_error_and_exit();
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		data->name = "mandelbrot";
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		data->name = "julia";
		if (argc == 4)
		{
			data->julia_cx = ft_atof(argv[2]);
			data->julia_cy = ft_atof(argv[3]);
		}
		else
		{
			data->julia_cx = -0.7;
			data->julia_cy = 0.27015;
		}
	}
	else
		print_error_and_exit();
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.min_r = -2.0;
	data.max_r = 2.0;
	data.min_i = -2.0;
	data.max_i = 2.0;
	parse_args(argc, argv, &data);
	data_init(&data);
	render(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
