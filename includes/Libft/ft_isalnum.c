/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:12:39 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:35:40 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c
			&& c <= '9'))
		return (8);
	else
		return (0);
}

// int	main(void)
// {
// 	int c;

// 	c = 'a';
// 	printf("%d\n", ft_isalnum(c));
// 	printf("%d\n", isalnum(c));
// 	return (0);
// }