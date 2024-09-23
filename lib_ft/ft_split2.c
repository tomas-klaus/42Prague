/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:54:32 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/23 18:27:44 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. count segments by reading string and incrementing when passing delimiter
2. malloc array of strings
3. count the lenght of each segment and malloc individual strings in the array
4. Assign values to the array of strings
 */

#include <stdio.h>
#include <stdlib.h>

int	countsegments(char const *s, char c)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while ((char)s[i])
	{
		printf("%c", s[i]);
		if ((char)s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	seglen(char const *s, char c, int start)
{
	int	i;
	int	newstart;

	newstart = start;
	i = 0;
	while (s[i] && s[i] != c)
	{
		newstart++;
	}
	return (newstart);
}

void	assignvalues(char **arr, int count, char const *s, char c)
{
	int	start;
	int	i;
	int	end;
	int	j;
	int	len;

	j = 0;
	start = 0;
	i = 0;
	while (i <= count)
	{
		end = seglen(s, c, start);
		len = end - start;
		arr[i] = malloc(len * sizeof(char));
		while (j < len)
		{
			arr[i][j] = s[start];
			start++;
			j++;
		}
		i++;
		start = end;
	}
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**array_of_strings;

	count = countsegments(s, c);
	array_of_strings = malloc((count + 1) * sizeof(char));
	assignvalues(array_of_strings, count, s, c);
	return (array_of_strings);
}

int	main(void)
{
	char const s[] = "hello, im, going, to, 42, school";
	char c = ',';
	printf("hello");
	char **arr = ft_split(s, c);
	for (int i = 0; i < 6; i++)
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
	}
	free(arr);

	return (0);
}