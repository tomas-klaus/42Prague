/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:54:08 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/01 16:34:33 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	callculatelen(char const *s, unsigned int start, size_t len)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (len + start > slen)
		len = (slen - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	char			*orig;
	unsigned int	i;
	size_t			j;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	len = callculatelen(s, start, len);
	orig = (char *)s;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == 0)
		return (0);
	while (s[i] && j < len)
	{
		substr[j] = orig[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}
/* 
#include <stdio.h>

int	main(void)
{
	char str[] = "012345678945495649456132";
	char *result;

	result = ft_substr(str, 9, 10);
	printf("%s\n", result);
	free(result);

	return (0);
} */