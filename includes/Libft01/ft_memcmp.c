/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:10:45 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:39:51 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n)
	{
		j = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		if (j != 0)
			return (j);
		i++;
	}
	return (0);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const void	*s1 = "aaaa";
// 	const void	*s2 = "aaab";
// 	size_t		n;

// 	n = 4;
// 	printf("%d\n", ft_memcmp(s1, s2, n));
// 	printf("%d\n", memcmp(s1, s2, n));
// 	return (0);
// }
// int	ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	size_t				i;
// 	const unsigned char	*ptr1 = (const unsigned char *)s1;
// 	const unsigned char	*ptr2 = (const unsigned char *)s2;

// 	i = 0;
// 	while (i < n && ptr1[i] == ptr2[i])
// 		i++;
// 	if (i == n)
// 		return (0);
// 	return (ptr1[i] - ptr2[i]);
// }
// if???does it need to?