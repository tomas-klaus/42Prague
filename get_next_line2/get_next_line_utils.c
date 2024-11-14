/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:17:20 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/11/13 16:54:21 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			result;
	void			*ptr;
	unsigned char	*p;
	size_t			i;

	i = 0;
	result = count * size;
	if (result == 0)
		result = 1;
	ptr = malloc(result);
	if (!ptr)
		return (NULL);
	p = ptr;
	while (i < result)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*og = s;
	size_t		i;
	size_t		len;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (*og == (char)c)
		{
			return ((char *)og);
		}
		og++;
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	joined_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined_str[i + j] = s2[j];
		j++;
	}
	joined_str[i + j] = '\0';
	free(s1);
	return (joined_str);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}
