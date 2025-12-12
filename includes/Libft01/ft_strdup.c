/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:43:21 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:46:00 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	len = ft_strlen(s) + 1;
	ptr = malloc(len);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

// int	main(void)
// {
// 	char	str[5] = "base";
// 	char	*dup_str;

// 	dup_str = ft_strdup(str);
// 	printf("str_ptr:%p\n", str);
// 	printf("str_str:%s\n", str);
// 	printf("dup_str:%p\n", dup_str);
// 	printf("dup_str:%s\n", dup_str);
// 	free(dup_str);
// 	return (0);
// }
// ft_strlenとか呼び出せるの？unn