/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:22:55 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/25 21:49:54 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_ft.h"

size_t	ft_strlen(const char *s)
{
	const char	*os = s;

	while (*s != '\0')
		s++;
	return (s - os);
}

int	ft_isspace(int c)
{
	const char	*ws = " \f\n\r\t\v";

	while (*ws != '\0')
		if (c == *ws++)
			return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * Check, if c is printable (c >= PRINTABLE_LOWER, c <= PRINTABLE_UPPER)
 * @param c	Character to check.
 * @return	Some positive value, if yes;
 * 			0 otherwise.
 */
int	ft_is_printable(int c)
{
	return (c >= PRINTABLE_LOWER && c <= PRINTABLE_UPPER);
}

/**
 * malloc()s new string of size new_buff_size and write up to
 * new_buff_size - 1 character to new buffer.
 *
 * If everything went perfect, also free()s str.
 * Resulting buffer is always NULL terminated.
 * @param str			String to reallocate.
 * @param old_buff_size	Size of old buffer.
 * @param new_buff_size	Size of a new buffer.
 * @return	NULL, if something went wrong or if new_buff_size is 0.
 * 			Otherwise, a pointer to a new buffer.
 */
char	*ft_realloc_str(char *str, unsigned int old_buff_size,
						unsigned int new_buff_size)
{
	char			*new_buff;
	unsigned int	i;

	if (!new_buff_size)
		return (NULL);
	new_buff = (char *) malloc(new_buff_size);
	if (new_buff == NULL)
		return (NULL);
	i = 0;
	while (i < old_buff_size)
	{
		new_buff[i] = str[i];
		i++;
	}
	new_buff[i] = '\0';
	free(str);
	return (new_buff);
}
