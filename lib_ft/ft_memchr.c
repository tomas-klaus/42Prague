/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:26:59 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/17 16:34:22 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*ptr == c)
		{
			return (ptr);
		}
		ptr++;
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void) {
	const char data[] = { 'H', 'e', 'l', 'l', 'o', 0, 'W', 'o', 'r', 'l', 'd' };
	char *result = ft_memchr(data, 'o', sizeof(data));
	if (result) {
		printf("First occurrence of 'o' found at position: %ld\n", result
			- data);
	} else {
		printf("'o' not found\n");
	}
	return (0);
}
 */