/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:50:45 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/23 15:39:30 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*result;
	int		j;
	i = 0;
	len = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = malloc(len * sizeof(char));
	if (result == 0)
		return (NULL);
	j = 0;
	while (s1[i])
	{
		result[j] = s1[i];
		j++;
        i++;
	}
    i=0;
	while (s2[i])
	{
		result[j] = s2[i];
		j++;
        i++;
	}
	return (result);
}
/* 
int	main(void)
{
	char s1[] = "hello";
	char s2[] = " world";

	printf("%s\n", ft_strjoin(s1,s2));
	return (0);
} */