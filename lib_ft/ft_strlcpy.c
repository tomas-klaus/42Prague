/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:24:04 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/17 13:36:07 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	int				i;
	size_t	j;
	char			*orig;

	orig = dst;
	i = 0;
	j = 0;
	if (size == 0)
		return (i);
	while (src[i] != '\0')
	{
		i++;
	}
	while (j != size - 1)
	{
		*dst = *src;
		dst++;
		src++;
		j++;
	}
	*dst = '\0';
	dst = orig;
	return (i);
}

#include <stdio.h>
int	main(void)
{
	char dst[5];
	char src[] = "Hello, World!";
	unsigned int size = 5;
	int j = ft_strlcpy(dst, src, size);
	printf("%d\n", j);

	printf("%s\n", dst);
	return (0);
}