/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:50:29 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/23 15:40:12 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	const char	*og = s;

	while (*og)
	{
		if (*og == c)
		{
			return ((char *)og);
		}
		og++;
	}
	if (c == '\0')
	{
		return ((char *)og);
	}
	return (0);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	// Sample string
	const char str[] = "Hello, World! This is a test string.";

	// Character to find (e.g., 's')
	char ch = ',';

	// Use strrchr to find the last occurrence of 's'
	char *last_occurrence = ft_strchr(str, ch);

	// Check if the character was found
	if (last_occurrence != NULL)
	{
		printf("The first occurrence of '%c' is at position: %ld\n", ch,
			last_occurrence - str);
		printf("Substring starting from the last occurrence: \"%s\"\n",
			last_occurrence);
	}
	else
	{
		printf("Character '%c' not found in the string.\n", ch);
	}

	printf("%s\n", str);

	return (0);
} */