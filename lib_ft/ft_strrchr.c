/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:36:38 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/17 16:08:49 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
    const char	*og = s;
	char	*ptr;

	ptr = 0;
	while (*og)
	{
		if (*og == c)
		{
			ptr = (char *)og;
		}
		og++;
	}
	if (c == '\0')
		return ((char *)og);
	return (ptr);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	// Sample string
	const char str[] = "Hello, World! This is a test string.";

	// Character to find (e.g., 's')
	char ch = '\0';

	// Use strrchr to find the last occurrence of 's'
	char *last_occurrence = ft_strrchr(str, ch);

	// Check if the character was found
	if (last_occurrence != NULL)
	{
		printf("The last occurrence of '%c' is at position: %ld\n", ch,
			last_occurrence - str);
		printf("Substring starting from the last occurrence: \"%s\"\n",
			last_occurrence);
	}
	else
	{
		printf("Character '%c' not found in the string.\n", ch);
	}

    printf ("%s\n", str);

	return (0);
}