/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:36:38 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/27 17:10:39 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*og = s;
	char		*ptr;
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(s);
	ptr = 0;
	while (i <= len)
	{
		if (*og == (char)c)
		{
			ptr = (char *)og;
		}
		og++;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *last_occurrence = ft_strrchr("teste", '\0');

	printf("%p\n", last_occurrence);

	return (0);
} */