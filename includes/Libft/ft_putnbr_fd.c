/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:54:32 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:43:33 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rec(int fd, long l)
{
	char	pochi;

	if (l >= 10)
		rec(fd, l / 10);
	pochi = (l % 10) + '0';
	write(fd, &pochi, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = (long)n;
	if (l < 0)
	{
		l *= -1;
		write(fd, "-", 1);
	}
	rec(fd, l);
}
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	ft_putnbr_fd(42, 1);
// 	return (0);
// }
