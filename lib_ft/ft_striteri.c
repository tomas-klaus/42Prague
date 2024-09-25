/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:06:55 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/09/25 21:11:34 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

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