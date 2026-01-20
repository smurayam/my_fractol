/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:54:02 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:58:32 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*new_src;
	size_t				i;

	ptr = (unsigned char *)dest;
	new_src = (const unsigned char *)src;
	if (new_src < ptr)
	{
		i = n;
		while (i > 0)
		{
			i--;
			ptr[i] = new_src[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ptr[i] = new_src[i];
			i++;
		}
	}
	return (dest);
}
//#include <stdio.h>

// int	main(void)
// {
// 	char		dest1[] = "aaaaa";
// 	const char	src1[] = "iiiii";
// 	size_t		n;
// 	char		dest[] = "aaaaa";
// 	const char	src[] = "iiiii";

// 	n = 3;
// 	printf("before ft_memmove : %s\n", dest);
// 	printf("before memmove : %s\n", dest1);
// 	ft_memmove(dest, src, n);
// 	memmove(dest1, src1, n);
// 	printf("after ft_memmove : %s\n", dest);
// 	printf("after memmove : %s\n", dest1);
// 	return (0);
// }

// about l22"cast";it is to be cast while you didnt explicit,
// its safer to just do it;

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	size_t				i;
// 	unsigned char		*d;
// 	const unsigned char	*s = (const unsigned char *)src;

// 	d = (unsigned char *)dest;
// 	i = 0;
// 	if (d < s)
// 	{
// 		i = 0;
// 		while (i < n)
// 		{
// 			d[i] = s[i];
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		i = n;
// 		while (i > 0)
// 		{
// 			i--;
// 			d[i] = s[i];
// 		}
// 	}
// 	return (dest);
// }

// what??????everything
// OpenSolaris_b135/lib/libparted/common/lib/memmove.c