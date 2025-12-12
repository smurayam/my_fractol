/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 06:39:15 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:36:36 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((97 <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1024);
	else
		return (0);
}

// int	main(void)
// {
// 	int	c;

// 	c = 'c';
// 	printf("%d\n", isalpha(c));
// 	printf("%d\n", ft_isalpha(c));
// 	return (0);
// }
