/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:37:28 by kluas             #+#    #+#             */
/*   Updated: 2024/08/20 13:37:42 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int		new_word;
	char	*orig;

	orig = str;
	new_word = 1;
	while (*str != '\0')
	{
		if ((*str >= 'a' && *str <= 'z') && new_word)
		{
			*str = *str - 32;
			new_word = 0;
		}
		else if ((*str >= 'A' && *str <= 'Z') && !new_word)
			*str = *str + 32;
		new_word = !((*str >= '0' && *str <= '9') || (*str >= 'a'
					&& *str <= 'z') || (*str >= 'A' && *str <= 'Z'));
		str++;
	}
	return (orig);
}

/* int	main(void)
{
	char	str[] = "salut,
			comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("Before: %s\n", str);
	printf("After: %s\n", ft_strcapitalize(str));
	return (0);
}
 */