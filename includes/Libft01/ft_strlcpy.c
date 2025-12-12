/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 03:38:29 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/28 03:48:15 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (j);
	while (i < size - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (j);
}

// size_t	strlcpy(char *dst, const char *src, size_t size);
// #include <stdio.h>
// #include <string.h>

// size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// int main(void)
// {
//     // 通常のテストケース
//     char dst1[50] = "initial_value";
//     char dst2[50] = "initial_value";
//     const char *src = "new_string";

//     size_t size1 = 5;

//     size_t size3 = 50;

//     printf("テスト1: コピーサイズ %zu\n", size1);
//     printf("ft_strlcpyの戻り値: %zu\n", ft_strlcpy(dst1, src, size1));
//     printf("標準strlcpyの戻り値: %zu\n", strlcpy(dst2, src, size1));
//     printf("ft_strlcpyの結果: %s\n", dst1);
//     printf("標準strlcpyの結果: %s\n\n", dst2);

//     // サイズ0のテスト
//     printf("テスト2: コピーサイズ 0\n");
//     printf("ft_strlcpyの戻り値: %zu\n", ft_strlcpy(dst1, src, 0));
//     printf("標準strlcpyの戻り値: %zu\n\n", strlcpy(dst2, src, 0));

//     // dstがNULLのテスト
//     printf("テスト3: dstがNULL\n");
//     printf("ft_strlcpyの戻り値: %zu\n\n", strlcpy(NULL, src, size3));

//     // srcがNULLのテスト
//     printf("テスト4: srcがNULL\n");
//     printf("ft_strlcpyの戻り値: %zu\n\n", ft_strlcpy(dst1, NULL, size3));

//     // dstとsrcの両方がNULLのテスト
//     printf("テスト5: dstとsrcの両方がNULL\n");
//     printf("ft_strlcpyの戻り値: %zu\n\n", strlcpy(NULL, NULL, size3));

//     return (0);
// }
// int	main(void)
// {
// 	char		dst1[50] = "111";
// 	const char	src1[50] = "222";
// 	size_t		size;
// 	char		dst[50] = "111";
// 	const char	src[50] = "222";

// 	size = 3;
// 	printf("ft_strlcpy(return): %zu\n", ft_strlcpy(dst, src, size));
// 	printf("ft_strlcpy(dst):%s\n", dst);
// 	printf("strlcpy(return):    %zu\n", strlcpy(dst1, src1, size));
// 	printf("strlcpy(dst)   :%s\n", dst1);
// 	// ft_strlcpy(dst, src, size);
// 	// strlcpy(dst1, src1, size);
// 	return (0);
// }
// #include <string.h>
// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != 0)
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	src_len;

// 	i = 0;
// 	src_len = ft_strlen(src);
// 	if (size == 0)
// 		return (src_len);
// 	while (i + 1 < size && src[i] != 0)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = 0;
// 	return (ft_strlen(src));
// }

// #include <stdio.h>

// int	main(void)
// {
// 	char		dst[10] = "aaaaa";
// 	const char	*src = "bbb";
// 	size_t		result;

// 	// printf("%zu\n", ft_strlcpy("aaaaa", "bbb", 7));
// 	result = ft_strlcpy(dst, src, 7);
// 	printf("%s\n", dst);
// 	printf("%zu\n", result);
// 	return (0);
// }
