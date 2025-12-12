/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:19:14 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:34:45 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
// void print_every_byte()
// int	main(void)
// {
// 	char	s[] = "nnnya";
// 	char	t[] = "nnnya";
// 	size_t	n;

// 	n = 2;
// 	printf("before:s:%s\n", s);
// 	printf("before:t:%s\n", t);
// 	ft_bzero(s, n);
// 	bzero(t, n);
// 	printf("after ft_bzero:%s\n", s);
// 	printf("after bzero:%s\n", t);
// 	return (0);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	size_t i;
// 	unsigned char *ptr;

// 	ptr = (unsigned char *)s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		ptr[i] = 0;
// 		i++;
// 	}
// }