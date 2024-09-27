/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:28:27 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/26 17:05:31 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

void	innerarray(char **arr, int count, char const *s, char c)
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
		i++;
		start += len;
	}
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
	innerarray(arr, count, s, c);
	assignvalues(arr, count, s, c);
	arr[count] = NULL;
	return (arr);
}
/* 
#include <unistd.h>

void	ft_print_result(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(void)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split("   lorem   ipsum dolor sit amet,
			consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
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
	return (0);
}
 */