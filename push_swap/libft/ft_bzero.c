/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:02:08 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/03 12:47:04 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	if (!s)
		return ;
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/* #include <stdio.h>
#include <string.h>

void	test_ft_bzero(void *s, size_t n, const char *expected)
{
	ft_bzero(s, n);
	if (memcmp(s, expected, n) == 0)
		printf("Test passed\n");
	else
		printf("Test failed\n");
}

int	main(void)
{
	char buffer1[10] = "AAAAAAAAA";
	char buffer2[10] = "AAAAAAAAA";
	char expected[10] = "\0\0\0\0\0AAAAA";

	// Test 1: Zero out the first 5 bytes
	test_ft_bzero(buffer1, 5, expected);

	// Test 2: Zero out the entire buffer
	memset(buffer2, 'A', 10);
	memset(expected, '\0', 10);
	test_ft_bzero(buffer2, 10, expected);

	// Test 3: Zero out 0 bytes (should do nothing)
	memset(buffer2, 'A', 10);
	test_ft_bzero(buffer2, 0, buffer2);

	ft_bzero(NULL, 42);

	return (0);
} */