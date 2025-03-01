/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:37:14 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/01 16:20:29 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z'))
	{
		return (0);
	}
	return (1024);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char src = 'L';

	printf("Mine: %d\n", ft_isalpha(src));
	printf("OG: %d\n", isalpha(src));
	return (0);
} */