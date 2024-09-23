/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:10:27 by kluas             #+#    #+#             */
/*   Updated: 2024/08/20 15:44:41 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int				i;
	unsigned int	j;
	char			*orig;

	orig = dest;
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
		*dest = *src;
		dest++;
		src++;
		j++;
	}
	*dest = '\0';
	dest = orig;
	return (i);
}

/* int	main(void)
{
	char dest[0];
	char src[] = "Hello, World!";
	unsigned int size = 0;
	int j = ft_strlcpy(dest, src, size);
	printf("%d\n", j);

	printf("%s\n", dest);
	return (0);
} */