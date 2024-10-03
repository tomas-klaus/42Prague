/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:20:48 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/01 16:20:44 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (!(c >= 0 && c <= 127))
	{
		return (0);
	}
	return (1);
}
/* 
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int src = 3;

	printf("Mine: %d\n", ft_isascii(src));
	printf("OG: %d\n", isascii(src));
	return (0);
} */