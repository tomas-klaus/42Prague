/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:36:22 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/23 11:23:42 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*start;
	char	*find;
	size_t	position;

	position = 0;
	if (*little == '\0')
		return ((char *)big);
	while (*big && position < len)
	{
		start =(char *)big;
		find = (char *)little;
		while (*big && *find && *big == *find)
		{
			big++;
			find++;
		}
		if (*find == '\0')
			return (start);
		big = start + 1;
		position++;
	}
	return (0);
}
/* 
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Test case 1: Substring is present within the length
    const char *haystack1 = "Hello, this is a simple test.";
    const char *needle1 = "simple";
    char *result1 =ft_strnstr(haystack1, needle1, 20); // Only search first 20 characters
    if (result1 != NULL)
        printf("Found '%s' in '%s': %s\n", needle1, haystack1, result1);
    else
        printf("'%s' not found in '%s'\n", needle1, haystack1);

    // Test case 2: Substring is not present within the length
    const char *haystack2 = "Hello, this is another example.";
    const char *needle2 = "example";
    char *result2 = ft_strnstr(haystack2, needle2, 10); // Limit search to 10 characters
    if (result2 != NULL)
        printf("Found '%s' in '%s': %s\n", needle2, haystack2, result2);
    else
        printf("'%s' not found in '%s'\n", needle2, haystack2);

    // Test case 3: Empty needle
    const char *haystack3 = "Hello, World!";
    const char *needle3 = "";
    char *result3 = ft_strnstr(haystack3, needle3, 15);
    if (result3 != NULL)
        printf("Found empty needle in '%s': %s\n", haystack3, result3);

    // Test case 4: Needle is longer than haystack
    const char *haystack4 = "Short";
    const char *needle4 = "This is a long needle";
    char *result4 = ft_strnstr(haystack4, needle4, 20);
    if (result4 != NULL)
        printf("Found '%s' in '%s': %s\n", needle4, haystack4, result4);
    else
        printf("'%s' not found in '%s'\n", needle4, haystack4);

    // Test case 5: Substring matches exactly at the start
    const char *haystack5 = "Matching";
    const char *needle5 = "Match";
    char *result5 = ft_strnstr(haystack5, needle5, 7); // Search the whole string
    if (result5 != NULL)
        printf("Found '%s' in '%s': %s\n", needle5, haystack5, result5);
    else
        printf("'%s' not found in '%s'\n", needle5, haystack5);

    return 0;
}
 */