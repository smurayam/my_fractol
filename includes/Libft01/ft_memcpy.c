/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:42:32 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 07:31:54 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*new_dest;
	const unsigned char	*new_src;
	size_t				i;

	new_dest = (unsigned char *)dest;
	new_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		new_dest[i] = new_src[i];
		i++;
	}
	return (new_dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*src = NULL;
// 	const char	*src1 = NULL;
// 	char		*dest;
// 	char		*dest1;

// 	// const char	src[] = 0;
// 	// const char	src1[] = 0;
// 	// char		dest[] = 0;
// 	// char		dest1[] = 0;
// 	dest = NULL;
// 	dest1 = NULL;
// 	// printf("before ft_memcpy:%s\n", dest);
// 	printf("before memcpy:%s\n", dest1);
// 	// ft_memcpy(dest, src, 3);
// 	memmove(dest1, src1, 0);
// 	// printf("after ft_memcpy:%s\n", dest);
// 	printf("after memcpy:%s\n", dest1);
// 	return (0);
// }

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	size_t i;
// 	unsigned char *d = (unsigned char *)dest;
// 	const unsigned char *s = (const unsigned char *)src;
// 	i = 0;

// 	while (i < n)
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	return (dest);
// }