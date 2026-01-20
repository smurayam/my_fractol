/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:01:29 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/25 01:06:17 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (2048);
	else
		return (0);
}

// int	main(void)
// {
// 	int	c;

// 	// c = '5';
// 	c = '1';
// 	printf("%d\n", ft_isdigit(c));
// 	printf("%d\n", isdigit(c));
// 	return (0);
// }
