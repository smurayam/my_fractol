/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:05:53 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:48:47 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	const char	*s;

// 	s = "wa-i";
// 	printf("%zu\n", ft_strlen(s));
// 	printf("%zu\n", strlen(s));
// 	return (0);
// }
