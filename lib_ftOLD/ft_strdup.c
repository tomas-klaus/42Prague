/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:07:35 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/01 16:30:01 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dest;
	int		i;

	len = ft_strlen(s);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char str[] = "lorem ipsum dolor sit amet";

	// A copy of source is created dynamically
	// and pointer to copy is returned.
		char *target = ft_strdup(str);

	//printf("terget: %s\n", target);

	int len;

	len = 0;
	while (target[len])
		len++;
	write(1, target, len);

	return (0);
} */