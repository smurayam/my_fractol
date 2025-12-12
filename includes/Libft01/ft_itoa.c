/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 03:35:50 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:37:31 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_digit(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*ptr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = check_digit(n);
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	ptr[i] = 0;
	i--;
	while (i >= 0 && n != 0)
	{
		ptr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (ptr);
}

// int	main(void)
// {
// 	int n = 1000034;
// 	printf("%d\n", n);
// 	printf("%s\n", ft_itoa(n));
// 	return (0);
// }

// 1234567n