/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:11:02 by smurayam          #+#    #+#             */
/*   Updated: 2024/11/15 05:1 by smurayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	first_dstlen;

	i = ft_strlen(dst);
	first_dstlen = ft_strlen(dst);
	j = 0;
	if (i >= size)
		return (size + ft_strlen(src));
	while (src[j] != 0 && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	j = ft_strlen(src);
	return (first_dstlen + ft_strlen(src));
}

/*
void	run_test(char *dst, const char *src, size_t size,
		const char *expected_dst, size_t expected_return)
{
	char	buffer[100];
	char	ft_buffer[100];
	size_t	result;
	size_t	ft_result;

	printf("src: \"%s\", size: %zu\n", src, size);
	strcpy(buffer, dst);
	strcpy(ft_buffer, dst);
	result = strlcat(buffer, src, size);
	ft_result = ft_strlcat(ft_buffer, src, size);
	printf("expected dst: \"%s\", actual dst: \"%s\"\n", buffer, ft_buffer);
	printf("expected return: %zu, actual return: %zu\n", result, ft_result);
	printf("Test %s\n\n", (strcmp(buffer, ft_buffer) == 0
			&& result == ft_result) ? "PASSED" : "FAILED");
	(void)expected_dst, (void)expected_return ;
}

int	main(void)
{
	// 1. 通常のケース
	run_test("hello", "world", 10, "helloworld", 10); // 追加してもバッファに収まるケース
	run_test("hello", "world", 5, "hello", 10);       // sizeが足りない場合（収まらない）
	// 2. 空文字列を渡す場合
	run_test("", "world", 10, "world", 5); // 空のdstにsrcを追加
	run_test("hello", "", 10, "hello", 5); // srcが空の場合
	// 3. サイズが0の場合
	run_test("hello", "world", 0, "hello", 5); // sizeが0の場合、dstは変更されない
	// 4. サイズが1の場合
	run_test("hello", "world", 1, "hello", 5); // sizeが1の場合もdstは変更されない
	// 5. サイズがぴったりdstの長さと同じ場合
	run_test("hello", "world", 5, "hello", 10); // dstの長さがsizeと同じ、srcは追加されない
	// 6. サイズがdst + srcの長さを超える場合
	run_test("hello", "world", 15, "helloworld", 10); // サイズが十分大きい場合、src全体が追加される
	// 7. NULLポインタを検証（例外処理は実装に応じて調整）
	// run_test(NULL, "world", 5, NULL, 0);           // NULLに対する動作（実装次第で追加）
	return (0);
}

int	main(void)
{
	char		dst[] = "iya";
	char		dst1[] = "iya";
	const char	src[] = "haaa";
	size_t		size;

	size = 3;
	printf("%zu\n", ft_strlcat(dst, src, size));
	printf("%s\n", dst);
	printf("%zu\n", strlcat(dst1, src, size));
	printf("%s\n", dst1);
	return (0);
}
*/
// unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
//{
//	unsigned int	dst_len;
//	unsigned int	src_len;
//	unsigned int	original_dst_len;

//	dst_len = 0;
//	src_len = 0;
//	while (dst[dst_len] != 0 && dst_len < size)
//		dst_len++;
//	original_dst_len = dst_len;
//	while (src[src_len] != 0)
//		src_len++;
//	if (dst_len == size)
//		return (size + src_len);
//	while (*src != 0 && dst_len < size - 1)
//	{
//		dst[dst_len] = *src;
//		dst_len++;
//		src++;
//	}
//	dst[dst_len] = 0;
//	return (original_dst_len + src_len);
//}
//#include <stdio.h>

// int	main(void)
//{
//	char	buffer[10] = "aaa";

//	printf("%u\n", ft_strlcat(buffer, "bbb", 10));
//	return (0);
//}
