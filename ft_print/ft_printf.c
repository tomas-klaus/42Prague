/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:39:05 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/02 15:35:50 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Start by parsing the format string.
2. Use va_start to access the variable arguments.
3. For each format specifier (%d, %s, etc.), extract the corresponding
   argument using va_arg.
4. Format the argument appropriately (like converting an integer to a string).
5. Store or print the resulting formatted string using write.
6. Once done, ensure to clean up (e.g., use free if you allocated memory).
 */

#include <stdarg.h>

int	format_check(const char *str, va_list args, int i)
{
	if (str[i] == 'd')
	{
		int j = va_arg(args, int); // Fetch the next int
		printf("%d", j);
	}
	// Add handling for other types (e.g., %s, %f, etc.)
	return (i);
}

int	parse_args(const char *str, va_list args)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++; // Move past '%'
			i = format_check(str, args, i);
		}
		else
			putchar(str[i]);
		// Just print the character if not a format specifier
		i++;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	parse_args(str, args);
	va_end(args); // Clean up
}

#include <stdio.h>

int	main(void)
{
	ft_printf("Number: %d\n", 42);
	printf("Number: %d\n", 42);
	return (0);
}