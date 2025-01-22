/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:06:23 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/03 14:13:53 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	if (!s1 || !s2)
		return (0);
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
		{
			return (ptr1[i] - ptr2[i]);
		}
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int	main(void) {
	//char str1[] = "1234567890";
	char str2[] = "1234567";
	size_t n = 10;

	int result_ft = ft_memcmp(NULL, str2, n);
	int result_libc = memcmp(NULL, str2, n);

	printf("ft_memcmp result: %d\n", result_ft);
	printf("memcmp result: %d\n", result_libc);

	if (result_ft < 0) {
		printf("ft_memcmp: First is less than second.\n");
	} else if (result_ft == 0) {
		printf("ft_memcmp: First is equal to second.\n");
	} else {
		printf("ft_memcmp: First is greater than second.\n");
	}

	if (result_libc < 0) {
		printf("memcmp: First is less than second.\n");
	} else if (result_libc == 0) {
		printf("memcmp: First is equal to second.\n");
	} else {
		printf("memcmp: First is greater than second.\n");
	}

	return (0);
}
 */