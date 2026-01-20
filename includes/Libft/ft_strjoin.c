/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 03:58:47 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:47:08 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	const int	size_s1 = ft_strlen(s1);
	const int	size_s2 = ft_strlen(s2);
	int			i;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(size_s1 + size_s2 + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size_s1)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < size_s2)
	{
		ptr[size_s1 + i] = s2[i];
		i++;
	}
	ptr[size_s1 + size_s2] = '\0';
	return (ptr);
}
