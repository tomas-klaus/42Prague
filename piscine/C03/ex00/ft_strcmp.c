/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:36:21 by kluas             #+#    #+#             */
/*   Updated: 2024/08/20 10:27:52 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((*s1 != '\0' || *s2 != '\0') && i == 0)
	{
		if (*s1 == *s2)
		{
			i = 0;
			s1++;
			s2++;
		}
		else
			i = (*s1 - *s2);
	}
	return (i);
}

/* int	main(void)
{
	char str1[] = "apple";
	char str2[] = "apples";
	char str3[] = "apple";
	char str4[] = "banana";

	printf("Comparison 1: %d\n", ft_strcmp(str1, str2));
	printf("Comparison 2: %d\n", ft_strcmp(str1, str3));
	printf("Comparison 3: %d\n", ft_strcmp(str1, str4));

	return (0);
} */