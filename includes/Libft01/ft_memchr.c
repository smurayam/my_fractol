/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:37:21 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:37:49 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const void	*s = "abcd";
// 	int			c;
// 	size_t		n;

// 	c = 'c';
// 	n = 3;
// 	printf("%s\n", (char *)ft_memchr(s, c, n));
// 	printf("%s\n", (char *)memchr(s, c, n));
// }

// // caution!!!pass
// void	*memchr(const void *s, int c, size_t n)
// {
// 	size_t				i;
// 	const unsigned char	*ptr = (const unsigned char *)s;

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (ptr[i] == (unsigned char)c)
// 			return ((void *)&ptr[i]);
// 		i++;
// 	}
// 	return (NULL);
// }
// // no understanding