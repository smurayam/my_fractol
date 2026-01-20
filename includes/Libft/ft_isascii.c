/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:30:33 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/25 01:06:04 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// int	main(void)
// {
// 	int c;
// 	c = 20;
// 	printf("%d\n", (ft_isascii(c)));
// 	printf("%d\n", isascii(c));
// }