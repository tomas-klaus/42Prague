/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:39:05 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/08 14:23:53 by tklaus           ###   ########.fr       */
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

#include "ft_printf.h"

int	format_check(char specifier, va_list args)
{
	int	i;

	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), specifier));
	else if (specifier == '%')
		return (ft_putchar('%'));
	else if (specifier == 'p')
	{
		if (!specifier)
			return (write(1, "(nil)", 5));
		i = 2;
		ft_putstr("0x");
		i += ft_putnbr_base(va_arg(args, unsigned long), 'x');
		return (i);
	}
	else
		return (0);
}

int	parse_args(const char *str, va_list args, int count)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			j = format_check(str[i], args);
			if (!j)
				return (0);
			count += j;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	count = parse_args(str, args, count);
	va_end(args);
	return (count);
}

/* #include <stdio.h>

int	main(void)
{
	ft_printf("Number: %d\n", 42);
	printf("Number: %d\n", 42);

	ft_printf("String: %s\n", "Hello, world!");
	printf("String: %s\n", "Hello, world!");

	ft_printf("Character: %c\n", 'A');
	printf("Character: %c\n", 'A');

	ft_printf("Unsigned: %u\n", 42);
	printf("Unsigned: %u\n", 42);

	ft_printf("Hexadecimal: %x\n", 42);
	printf("Hexadecimal: %x\n", 42);

	ft_printf("Hexadecimal: %X\n", 42);
	printf("Hexadecimal: %X\n", 42);

	ft_printf("Percent: %%\n");
	printf("Percent: %%\n");

	ft_printf("Mixed: %d %s %c %u %x %X %%\n", 42, "Hello, world!", 'A', 42, 42,
		42);
	printf("Mixed: %d %s %c %u %x %X %%\n", 42, "Hello, world!", 'A', 42, 42,
		42);

	ft_printf("Hello");
	printf("Hello");
	return (0);
} */
