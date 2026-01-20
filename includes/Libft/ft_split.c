/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 07:07:53 by smurayam          #+#    #+#             */
/*   Updated: 2025/03/21 01:09:52 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

int	length_of_words(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

char	**free_return_null(char **ptr, int i)
{
	int	love;

	love = 0;
	while (love < i)
	{
		free(ptr[love]);
		love++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		word_len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ptr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (i < count_words(s, c))
	{
		while (s[j] == c)
			j++;
		word_len = length_of_words(&s[j], c);
		ptr[i] = ft_substr(s, j, word_len);
		if (!ptr[i])
			return (free_return_null(ptr, i));
		j += word_len;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

// int	main(void)
// {
// 	char	**tab;
// 	char	c;

// 	// char const	*s;
// 	// s = strdup("Toripouille");
// 	c = ' ';
// 	tab = ft_split("aiueo kaki kue", ' ');
// 	// tab = ["aiueo", "kaki", "kue"];
// 	for (int i = 0; tab[i]; i++)
// 		printf("%s\n", tab[i]);
// 	// printf("%d\n", count_words(s, c)); // 3
// 	// // printf("%p\n", heads_line(s, c));
// 	// // printf("%s\n", heads_line(s, c));
// 	// printf("%p\n", ft_split(s, c));
// 	return (0);
// }
// // its matter whether its C or notC
// mallocno null gard and substr null gard free