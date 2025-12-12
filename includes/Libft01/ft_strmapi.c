/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:14:56 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 05:40:03 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	ptr = ft_strdup(s);
	if (!ptr)
		return (NULL);
	while (s[i] != 0)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}
// static char	my_upchar(unsigned int i, char c)
// {
// 	(void)i;
// 	if ('a' <= c && c <= 'z')
// 		c -= 32;
// 	return (c);
// }

// size_t		ft_strlen(const char *s);
// int	main(void)
// {
// 	char const *s = "gurara";

// 	char (*f)(unsigned int, char) = my_upchar;
// 	printf("%s\n", ft_strmapi(s, f));
// 	return (0);
// }