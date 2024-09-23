/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft_part1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:01:56 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/25 22:31:04 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lib_ft.h"

#define JUST_ONE_BYTE	1

/**
 * Prints a character to provided stream.
 * @param fd	Stream where to write a character.
 * @Param c		A character to print.
 * @return	0, if everything went fine;
 * 			Some other positive value otherwise.
 */
int	ft_fd_putchar(int fd, char c)
{
	if (write(fd, &c, JUST_ONE_BYTE) == -1)
		return (1);
	return (0);
}

#undef JUST_ONE_BYTE

/**
 * Returns amount of digits in num.
 * @param num	A number to count digits in.
 * @return Amount of digits in num.
 */
int	ft_count_digits(int num)
{
	int	digits;

	digits = 0;
	while (num)
	{
		num /= 10;
		digits++;
	}
	if (!digits)
	{
		digits++;
	}
	return (digits);
}

/**
 * Prints a number to provided stream.
 * @param fd	Stream where to write a number.
 * @Param nb	A number to print.
 * @return	0, if everything went fine;
 * 			Some other positive value otherwise.
 */
int	ft_putnbr(int fd, int nb)
{
	int	digits;
	int	i;
	int	buff;

	if (nb < 0)
		if (ft_fd_putchar(fd, '-'))
			return (1);
	digits = ft_count_digits(nb);
	while (digits)
	{
		buff = nb;
		i = --digits;
		while (i--)
			buff /= 10;
		buff %= 10;
		if (buff < 0)
			buff = -buff;
		if (ft_fd_putchar(fd, '0' + buff))
			return (1);
	}
	return (0);
}

/**
 * Swaps two variables. Both must have the same size.
 * @param a	First variable.
 * @param b	Second variable.
 * @param n	Size of those variables.
 */
void	ft_swap(void *a, void *b, unsigned int n)
{
	unsigned char	swap;

	while (n--)
	{
		swap = *((unsigned char *) a);
		*((unsigned char *) a++) = *((unsigned char *) b);
		*((unsigned char *) b++) = swap;
	}
}

/**
 * Prints a string to provided output stream.
 * @param fd	Stream where to write a string.
 * @Param c		A string to print.
 * @return	0, if everything went fine;
 * 			Some other positive value otherwise.
 */
int	ft_fd_putstr(int fd, const char *str)
{
	if (write(fd, str, ft_strlen(str)) == -1)
		return (1);
	return (0);
}
