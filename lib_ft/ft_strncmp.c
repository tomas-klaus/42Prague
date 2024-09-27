/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:10:29 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/26 15:00:07 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	j;
	int		i;

	i = 0;
	j = 0;
	while (j < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
		j++;
	}
	return (0);
}
/* 
#include <stdio.h>

int	main(void)
{
	int result = ft_strncmp("test\200", "test\0", 6);
	printf("Result: %d\n", result);

	return (0);
} */