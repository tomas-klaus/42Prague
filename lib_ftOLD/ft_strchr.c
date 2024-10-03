/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:50:29 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/02 15:41:03 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*og = s;
	size_t		i;
	size_t		len;

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
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *last_occurrence = ft_strchr("teste", '\0');

	printf("%p\n", last_occurrence);

	return (0);
} */