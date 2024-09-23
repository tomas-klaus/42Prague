/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:26:06 by kluas             #+#    #+#             */
/*   Updated: 2024/08/20 09:28:04 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	j;

	j = 0;
	while (j < n && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		j++;
	}
	return (0);
}

/* int	main(void)
{
	char str1[] = "abcdef";
	char str2[] = "abcxyz";

	int result = ft_strncmp(str1, str2, 3);
	printf("Result: %d\n", result);

	result = ft_strncmp(str1, str2, 4);
	printf("Result: %d\n", result);

	result = ft_strncmp(str1, str2, 0);
	printf("Result: %d\n", result);

	return (0);
} */