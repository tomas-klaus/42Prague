/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:34:36 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/20 13:37:32 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*orig;

	orig = str;
	while (*str != '\0')
	{
		if (*str >= 97 && *str <= 122)
		{
			*str = *str - 32;
		}
		str++;
	}
	return (orig);
}

/* int	main(void)
{
	char src[] = "heLLo";

	printf("%s\n", ft_strupcase(src));
	return (0);
} */