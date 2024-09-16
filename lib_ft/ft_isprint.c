/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:32:04 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/16 14:50:29 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (!(c >= 33 && c <= 126))
	{
		return (0);
	}
	return (16384);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int src = 'd';

	printf("Mine: %d\n", ft_isprint(src));
	printf("OG: %d\n", isprint(src));
	return (0);
} */