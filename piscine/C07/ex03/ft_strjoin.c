/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:16:48 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/29 16:49:31 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*orig;

	orig = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (orig);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*result;
	int		j;

	i = 0;
	len = 1;
	while (i++ < size)
	{
		len += sizeof(*strs[i]);
	}
	len += sizeof(*sep) * (size - 1);
	result = malloc(len * sizeof(char));
	result[0] = '\0';
	if (size == 0)
		return (result);
	j = 0;
	while (j < size)
	{
		ft_strcat(result, strs[j]);
		if (j < size - 1)
			ft_strcat(result, sep);
		j++;
	}
	return (result);
}

/* int	main(void)
{
	char *strs[] = {NULL};
	char *sep = ", ";
	int size = 0;

	printf("%s\n", ft_strjoin(size, strs, sep));
	return (0);
} */