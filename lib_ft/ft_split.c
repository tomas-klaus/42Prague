/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:28:27 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/23 23:55:51 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	countsegments(char const *s, char c)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	assignvalues(char **arr, int count, char const *s, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (i <= count)
	{
		j = 0;
		while (s[n] && s[n] != c)
		{
			arr[i][j] = s[n];
			j++;
			n++;
		}
		i++;
		n++;
	}
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
		i++;
	}
	return (newstart);
}

void	innerarray(char **arr, int count, char const *s, char c)
{
	int	start;
	int	i;
	int	end;

	start = 0;
	i = 0;
	while (i <= count)
	{
		end = seglen(s, c, start);
		arr[i] = malloc((end - start) * sizeof(char));
		i++;
		start = end;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;

	count = countsegments(s, c);
	arr = malloc((count + 1) * sizeof(char *));
	innerarray(arr, count, s, c);
	assignvalues(arr, count, s, c);
	return (arr);
}

int	main(void)
{
	char const s[] = "henllo, im, going, to, 42 , school";
	char c = ',';
	char **arr = ft_split(s, c);
	for (int i = 0; i < 10; i++)
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
	}
	free(arr);

	return (0);
}