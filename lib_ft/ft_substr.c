/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:54:08 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/23 14:33:23 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	char	*dest;
	size_t	i;

	dest = malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i <= n && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	char			*orig;

	orig = (char *)s;
	if (orig == NULL)
		return (NULL);
	i = 0;
	while (i < start && *orig)
	{
		orig++;
		i++;
	}
	if (!*orig)
		return ("");
	substr = ft_strndup(orig, len);
	if (substr == 0)
		return (0);
	return (substr);
}
/* 
#include <stdio.h>

int	main(void)
{
	// Test cases
	char *str1 = "Hello, world!";
	char *result;

	// Case 1: Substring from index 0 with length 5 ("Hello")
	result = ft_substr(str1, 0, 5);
	printf("Case 1: %s\n", result); // Expected: "Hello"
	free(result);

	// Case 2: Substring from index 7 with length 5 ("world")
	result = ft_substr(str1, 7, 5);
	printf("Case 2: %s\n", result); // Expected: "world"
	free(result);

	// Case 3: Substring starting beyond the length of the string (should return empty string)
	result = ft_substr(str1, 50, 5);
	printf("Case 3: %s\n", result); // Expected: "" (empty string)
	//free(result);

	// Case 4: Substring with length longer than the remaining part of the string
	result = ft_substr(str1, 7, 100);
	printf("Case 4: %s\n", result); // Expected: "world!"
	free(result);

	// Case 5: Substring from an empty string
	result = ft_substr("", 0, 10);
	printf("Case 5: %s\n", result); // Expected: "" (empty string)
	//free(result);

	// Case 6: NULL string passed
	result = ft_substr(NULL, 0, 5);
	printf("Case 6: %s\n", result == NULL ? "NULL" : result);
	// Expected: "NULL"

	return (0);
} */