/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:46:31 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 04:43:28 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*point;
	size_t	total_size;

	total_size = nmemb * size;
	if (total_size == 0)
		return (malloc(0));
	if (total_size / nmemb != size)
		return (NULL);
	point = malloc(total_size);
	if (point == NULL)
		return (NULL);
	ft_bzero(point, total_size);
	return (point);
}

// int	main(void)
// {
// 	size_t	nmemb;
// 	size_t	size;

// 	nmemb = 0;
// 	size = 0;
// 	printf("%p\n", ft_calloc(nmemb, size));
// 	printf("%p\n", calloc(nmemb, size));
// 	return (0);
// }

// when you use size_t, think about size_t's max

// #include <stdlib.h>
// #include <string.h>

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	char	*ptr;
// 	size_t	i;

// 	ptr = malloc(nmemb * size);
// 	i = 0;
// 	if (ptr == NULL)
// 		return (NULL);
// 	while (i < nmemb * size)
// 	{
// 		ptr[i] = 0;
// 		i++;
// 	}
// 	return (ptr);
// }
