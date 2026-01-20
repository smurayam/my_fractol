/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:38:45 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:34:26 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while ('0' <= *nptr && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}
// size_t	ft_strlen(const char *s);

// char	ft_polish(const char *nptr, int ptr, int i)
// {
// 	while (nptr)
// 	{
// 		if (*((char *)nptr + i) == '-')
// 			ptr *= -1;
// 		if (*((char *)nptr + i) == ' ' || (*(char *)nptr) + i == '\f'
// 			|| (*(char *)nptr + i) == '\n' || (*(char *)nptr + i) == '\r'
// 			|| (*(char *)nptr + i) == '\t' || (*(char *)nptr + i) == '\v')
// 			i++;
// 	}
//  return(*(char *)nptr);
// }

// int	ft_atoi(const char *nptr)
// {
// 	int	result;
// 	int	i;
// 	int	j;

// 	result = 0;
// 	i = 0;
// 	j = ft_strlen(nptr);
// 	// char ft_polish(const char *nptr, int ptr, int i);
// 	// ft_polish(nptr, result, i);
// 	while (*nptr && (*nptr == ' ' || *nptr == '\f' || *nptr == '\n'
// 			|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v'))
// 		nptr++;
// 	while (nptr[i] && ('0' <= nptr[i] && nptr[i] <= '9'))
// 	{
// 		result = ((char)nptr[i] - '0') + result * 10;
// 		j--;
// 		i++;
// 	}
// 	return (result);
// }

// int	main(void)
// {
// 	const char	nptr[] = "10";

// 	printf("%d\n", ft_atoi(nptr));
// 	printf("%d\n", atoi(nptr));
// 	return (0);
// }

// #include <stdio.h>
// #include <stdlib.h>

// int	ft_atoi(const char *nptr)
// {
// 	int	i;

// 	i = 0;
// 	return (i);
// }
// int	main(void)
// {
// 	const char	*nptr = "yaaaa";

// 	return (0);
// }
