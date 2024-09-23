/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:12:43 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/23 17:39:53 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/* loop through the set and compare with character,
if there is a match, return 1, otherwise return 0 */
int	isset(char const *set, char character)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == character)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		fromstart;
	int		fromend;
	int		i;
	int		len;
	int		j;
	char	*string;

	fromstart = 0;
	fromend = 0;
	i = 0;
	len = ft_strlen((char *)s1) - 1;
	j = len;
	while (isset(set, s1[i]))
	{
		fromstart++;
		i++;
	}
	while (isset(set, s1[j]))
	{
		fromend++;
		j--;
	}
	string = ft_substr(s1, fromstart, (len - (fromstart + fromend)));
	return (string);
}
/* 
#include <stdio.h>

int	main(void)
{
	char const set[] = " +-";
	char const s1[] = "hel-lo";
	char *result = ft_strtrim(s1, set);

	printf("%s", result);
} */