/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:12:43 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/27 16:53:26 by tklaus           ###   ########.fr       */
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
	int		len;
	char	*trimmed_string;
	int		trimmed_len;

	fromstart = 0;
	fromend = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1) - 1;
	while (isset(set, s1[fromstart]))
		fromstart++;
	while (isset(set, s1[len]) && len > fromstart)
		len--;
	trimmed_len = len - fromstart + 1;
	trimmed_string = malloc((trimmed_len + 1) * sizeof(char));
	if (!trimmed_string)
		return (NULL);
	ft_memcpy(trimmed_string, s1 + fromstart, trimmed_len);
	trimmed_string[trimmed_len] = '\0';
	return (trimmed_string);
}
/*
#include <stdio.h>

int	main(void)
{
	char *result = ft_strtrim("   \t  \n\n \t\t  \n\n\nHello
	\t  Please\n Trim me !\n   \n \n \t\t\n  "," \n\t");

	printf("%s", result);
} */