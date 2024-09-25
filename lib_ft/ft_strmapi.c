/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:45:52 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/09/25 13:06:31 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*c;

	len = ft_strlen((char *)s);
	i = 0;
	c = malloc((len + 1) * sizeof(char));
	if (!c)
		return (NULL);
	while (s[i])
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
/* 
char	modify_char(unsigned int i, char c)
{
	return (c + i - i + 1);
}

int	main(void)
{
	char const *s = "abcdef";

	char *result = ft_strmapi(s, modify_char);
	printf("Original string: %s\n", s);
	printf("Modified string: %s\n", result);

	free(result);

	return (0);
} */