/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:10:29 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/17 16:25:10 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
int		ft_strncmp(const char *s1, const char *s2, size_t n){
    
	size_t	j;
    int i = 0;

	j = 0;
	while (j < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
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