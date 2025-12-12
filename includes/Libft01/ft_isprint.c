/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:00:31 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/25 01:06:23 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

// int	main(void)
// {
// 	int c;
// 	c = 30;
// 	printf("%d\n", (ft_isprint(c)));
// 	printf("%d\n", (isprint(c)));
// 	return (0);
// }