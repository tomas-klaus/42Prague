/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:28:27 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/19 21:27:50 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countsegments(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	seglen(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

int	innerarray(char **arr, int count, char const *s, char c)
{
	int	start;
	int	i;
	int	len;

	start = 0;
	i = 0;
	while (i < count)
	{
		while (s[start] == c)
			start++;
		len = seglen(s, c, start);
		arr[i] = malloc((len + 1) * sizeof(char));
		if (!arr[i])
		{
			while (i >= 0)
				free(arr[i--]);
			free(arr);
			return (0);
		}
		i++;
		start += len;
	}
	return (1);
}

void	assignvalues(char **arr, int count, char const *s, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (i < count)
	{
		while (s[n] == c)
			n++;
		j = 0;
		while (s[n] && s[n] != c)
		{
			arr[i][j++] = s[n++];
		}
		arr[i][j] = '\0';
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;

	if (!s)
		return (NULL);
	count = countsegments(s, c);
	arr = malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!innerarray(arr, count, s, c))
		return (NULL);
	assignvalues(arr, count, s, c);
	arr[count] = NULL;
	return (arr);
}
/* #include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_print_result(char const *s)
{
	int		len;
	char	**arr;
	int		i;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
} */
/* void	test_ft_split(char const *s, char c)
{
	i = 0;
	arr = ft_split(s, c);
	if (!arr)
	{
		ft_print_result("NULL\n");
	}
	else
	{
		while (arr[i] != NULL)
		{
			ft_print_result(arr[i]);
			write(1, "\n", 1);
			free(arr[i]); // Free each string
			i++;
		}
		free(arr); // Free the array of strings
	}
}

int	main(void)
{
	// Test 1: Normal case
	printf("Test 1: Normal case\n");
	test_ft_split("   lorem   ipsum dolor sit amet,
		consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');

	// Test 2: Empty string
	printf("Test 2: Empty string\n");
	test_ft_split("", ' ');

	// Test 3: String with no delimiters
	printf("Test 3: String with no delimiters\n");
	test_ft_split("loremipsumdolorsitamet", ' ');

	// Test 4: String with only delimiters
	printf("Test 4: String with only delimiters\n");
	test_ft_split("     ", ' ');

	// Test 5: String with multiple consecutive delimiters
	printf("Test 5: String with multiple consecutive delimiters\n");
	test_ft_split("lorem   ipsum   dolor", ' ');

	// Test 6: Allocation failure simulation
	printf("Test 6: Allocation failure simulation\n");
	char **arr = malloc(1 * sizeof(char *));
	if (!arr)
		ft_print_result("NULL\n");
	else
		free(arr);

	return (0);
} */