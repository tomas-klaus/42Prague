/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:12:37 by kluas             #+#    #+#             */
/*   Updated: 2024/08/21 10:24:49 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*start;
	char	*find;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		start = str;
		find = to_find;
		while (*str && *find && *str == *find)
		{
			str++;
			find++;
		}
		if (*find == '\0')
			return (start);
		str = start + 1;
	}
	return (0);
}

/* int	main(void)
{
	char str[] = "-62,47 +62,47";
	char to_find[] = "47";

	// Calling ft_strstr to find the substring
	char *result = ft_strstr(str, to_find);

	// Printing the result
	if (result)
	{
		printf("Substring found: %s\n", result);
	}
	else
	{
		printf("Substring not found.\n");
	}

	return (0);
} */