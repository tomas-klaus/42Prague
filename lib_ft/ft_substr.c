/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:54:08 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/26 18:02:37 by tklaus           ###   ########.fr       */
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
	while (i < n && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	char			*orig;

	if (!s)
		return (NULL);
	orig = (char *)s;
	i = 0;
	while (i < start && *orig)
	{
		orig++;
		i++;
	}
	if (!orig)
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
	char str[] = "";
	char *result;

	result = ft_substr(str, 5, 0);
	printf("%s\n", result);
	free(result);

	return (0);
} */