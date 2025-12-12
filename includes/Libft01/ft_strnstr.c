/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:26:22 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:51:58 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little[0])
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j] && (i
				+ j) < len)
		{
			j++;
		}
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// #include <string.h>
// char	*strnstr(const char *big, const char *little,size_t len);

// int	main(void)
// {
// 	printf("%s\n", ft_strnstr("qwertyuiop", "ertyu", 10));
// 	printf("%s\n", strnstr("qwertyuiop", "ertyu", 10));
// 	return (0);
// }

// int	main(void)
// {
// 	const char	*big = "hey, baby";
// 	const char	*little = "baby";
// 	size_t		len;

// 	len = 10;
// 	char *strnstr(const char *big, const char *little, size_t len);
// 	printf("%s\n", ft_strnstr(big, little, len));
// 	printf("%s\n", strnstr(big, little, len));
// 	return (0);
// }
// #include <stdio.h>
// #include "libft.h"

// char	ft_strnstr(const char *big, const char *little,unsigned int len)
// {
// 	unsigned int	i;
// 	unsigned int	j;

// 	i = 0;
// 	j = 0;
// 	while (big[j] != 0)
// 	{
// 		while (big[j] == little[i] && j < len && little[i] != 0)
// 		{
// 			i++;
// 		}
// 		j++;
// 	}
// 	if (little[i] == 0)
// 		return (big[0]);
// 	else
// 		return (0);
// }

// int	main(void)
// {
// 	printf("%c\n", ft_strnstr("aaabba", "bb", 6));
// 	return (0);
// }
// write yourself