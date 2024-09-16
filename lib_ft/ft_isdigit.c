/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:09:17 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/16 13:14:37 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
	{
		return (0);
	}
	return (2048);
}


/* #include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char src = 'u';

	printf("Mine: %d\n", ft_isdigit(src));
    printf("OG: %d\n", isdigit(src));
	return (0);
} */