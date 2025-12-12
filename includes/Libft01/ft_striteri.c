/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:03:31 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:56:28 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
	{
		f(i, &s[i]);
		i++;
	}
}

// void	my_upchar(unsigned int i, char *c)
// {
// 	(void)i;
// 	if ('a' <= *c && *c <= 'z')
// 		*c -= 32;
// }

//#include <stdio.h>
// int	main(void)
// {
// 	char s[] = "nnnya";
// 	ft_striteri(s, my_upchar);
// 	printf("%s\n", s);
// 	return (0);
// }