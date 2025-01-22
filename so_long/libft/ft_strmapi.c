/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:45:52 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/10/03 14:02:10 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*c;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
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

/* #include <stdio.h>
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