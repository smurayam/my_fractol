/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:46:32 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:54:58 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == 0)
		return ((char *)(s + i));
	return (NULL);
}

//#include <stdio.h>
// int	main(void)
// {
// 	int			c;
// 	const char	s[] = "aaa";

// 	c = 'e';
// 	// printf("%s\n", strchr(NULL, c));
// 	printf("%s\n", ft_strchr(s, 97));
// 	return (0);
// }

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }
// char	*ft_strchr(const char *s, int c)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (s[i] != 0)
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)s[i]);
// 		i++;
// 	}
// 	if (c == 0)
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

// // cannot understand under 34