/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:22:07 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 07:29:14 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	const size_t	s_len = ft_strlen(s);
	char			*ptr;

	if (!s)
		return (NULL);
	if (start >= s_len)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = 0;
		return (ptr);
	}
	if (len > s_len - start)
		len = s_len - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	while (len > ++i)
		ptr[i] = s[start + i];
	ptr[i] = 0;
	return (ptr);
}

// #include <stdio.h>

// int		ft_strlen(const char *s);

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	int i;
// 	i = 0;
// 	char	*ptr;
// 	while(s[i] != 0)
// 	{
// 		i ++;
// 	}
// 	return (ptr);
// }

// int	main(void)
// {
// 	// char	s[] = "I am waking up";

// 	// printf(s, 4, 6); // m wa
// 	printf("[%s]", ft_substr("", 0, 0));
// 	return (0);
// }