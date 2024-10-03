/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:26:59 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/03 14:15:03 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	if (!s)
		return (0);
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
		{
			return (ptr);
		}
		ptr++;
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>
 */
/* int	main(void)
{
	//int tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	// Use ft_memchr with correct size
	int *result = (int *)ft_memchr(NULL, -1, 7 * sizeof(int));
	if (result != NULL)
	{
		// Print result as integer since it's an int array
		printf("Found value: %d\n", *result);
	}
	else
	{
		printf("Value not found.\n");
	}

	return (0);
} */