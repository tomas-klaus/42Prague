/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:24 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/01 16:20:15 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z') && !(c >= '0'
			&& c <= '9'))
	{
		return (0);
	}
	return (8);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char src = '-';

	printf("Mine: %d\n", ft_isalnum(src));
	printf("OG: %d\n", isalnum(src));
	return (0);
} */