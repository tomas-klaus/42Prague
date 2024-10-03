/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:06:55 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/10/01 16:30:30 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}
/* 
#include <ctype.h>
#include <stdio.h>

void	test(unsigned int i, char *c)
{
	if (i > 0)
	{
		if (islower(*c))
			*c = toupper(*c);
	}
}

int	main(void)
{
	// Test string
	char s[] = "hello world!";

	// Print original string
	printf("Original string: %s\n", s);

	// Apply ft_striteri to the string using the test function
	ft_striteri(s, test);

	// Print the modified string
	printf("Modified string: %s\n", s);

	return (0);
} */