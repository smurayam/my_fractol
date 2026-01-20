/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:42:06 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:56:56 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (ptr);
}

//#include <stdio.h>

// int	main(void)
// {
// 	char	s[] = "ooowao";
// 	char	t[] = "ooowao";
// 	int		c;
// 	size_t	n;

// 	c = 47;
// 	n = 3;
// 	printf("before:s:%s\n", s);
// 	printf("before:t:%s\n", t);
// 	ft_memset(s, c, n);
// 	memset(t, c, n);
// 	printf("after ft_memset:%s\n", s);
// 	printf("after memset:%s\n", t);
// 	return (0);
// }
// when you treat memori, use unsigned char;
// ok(or try again main)

// void	*ft_memset(void *s, int c, unsigned int n)
// {
// 	unsigned int	i;
// 	unsigned char	*ptr;

// 	i = 0;
// 	ptr = (unsigned char *)s;
// 	while (i < n)
// 	{
// 		ptr[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (s);
// }

// #include <stdio.h>

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

// int	main(void)
// {
// 	char str[] = "i ate pudding";
// 	unsigned int len = ft_strlen(str);
// 	printf("%u\n", len);
// 	return (0);
// }