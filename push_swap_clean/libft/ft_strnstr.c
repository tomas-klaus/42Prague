/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:36:22 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/03 14:16:07 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big || !little)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i + j] && i + j < len && big[i
				+ j] == little[j])
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*result1;

	// Test case: Both haystack and needle are NULL
	result1 = ft_strnstr(NULL, NULL, 15);
	if (result1 != NULL)
		printf("ft_strnstr: Found\n");
	else
		printf("ft_strnstr: Not found\n");
	// Test case: Both haystack and needle are NULL using original strnstr
	result1 = strnstr(NULL, NULL, 15);
	if (result1 != NULL)
		printf("strnstr: Found\n");
	else
		printf("strnstr: Not found\n");
	return (0);
}
 */