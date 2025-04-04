/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:34:37 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/12 19:34:30 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (0);
	dst_len = 0;
	src_len = 0;
	i = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] != '\0' && dst_len + i < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/* #include <stdio.h>

int	main(void)
{
	char dst[10] = "";
	char src[] = "hello";
	size_t result;

	result = ft_strlcat(dst, src, 10);
	printf("Resulting string: %s\n", dst);
	printf("Total length tried to create: %zu\n", result);
	return (0);
} */