/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:36:22 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/26 14:29:28 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*start;
	char	*find;
	size_t	position;
	size_t	j;

	position = 0;
	if (*little == '\0')
		return ((char *)big);
	while (*big && position < len)
	{
		start = (char *)big;
		find = (char *)little;
		j = 0;
		while (*big && *find && *big == *find && position + j < len)
		{
			big++;
			find++;
			j++;
		}
		if (*find == '\0')
			return (start);
		big = start + 1;
		position++;
	}
	return (NULL);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*haystack1 = "lorem ipsum dolor sit amet";
	const char	*needle1 = "dolor";
	char		*result1;

	// Test case 1: Substring is present within the length
	result1 = ft_strnstr(haystack1, needle1, 15);
	// Only search first 20 characters
	if (result1 != NULL)
		printf("Found '%s' in '%s': %s\n", needle1, haystack1, result1);
	else
		printf("'%s' not found in '%s'\n", needle1, haystack1);
}
 */