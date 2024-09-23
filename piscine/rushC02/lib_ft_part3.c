/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft_part3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:18:58 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/25 21:50:39 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lib_ft.h"

/**
 * A wrapper for ft_realloc_str() with arguments:
 * str, (BUFF_INC + strlen(*str) * BUFF_MULT).
 *
 * Useful to bypass Norminette's check for 25 lines per a function.
 * @param str	A pointer to a buffer to extend.
 * @param n		Pointer to variable, holding size of str buffer.
 * @return	0, if everything went alright;
 * 			Some positive value otherwise.
 */
int	ft_extend_str(char **str, size_t *n)
{
	char	*new_buff;

	new_buff = ft_realloc_str(*str, *n, BUFF_INC + (*n * BUFF_MULT));
	if (new_buff == NULL)
		return (1);
	*str = new_buff;
	*n = BUFF_INC + (*n * BUFF_MULT);
	return (0);
}

#define JUST_ONE_BYTE	1
#define FOR_NULL_TERM	1

/**
 * Cast from ssize_t to size_t looks really gloomy :p
 *
 * Reads a line (until '\n' or '\0') from fd file descriptor.
 * @param lineptr	Where to store the line.
 * @param n			Pointer to variable, holding size of lineptr buffer.
 * @param fd		File descriptor to read line from.
 * @return	Amount of bytes read from fd.
 * 			-1 in case of fail.
 */
ssize_t	ft_fd_getline(char **lineptr, size_t *n, int fd)
{
	ssize_t	read_bytes;
	ssize_t	read_status;

	read_bytes = 0;
	while (42)
	{
		if (!((size_t)(read_bytes + FOR_NULL_TERM) < *n))
			if (ft_extend_str(lineptr, n))
				return (-1);
		read_status = read(fd, *lineptr + read_bytes, JUST_ONE_BYTE);
		if (read_status == -1)
			return (-1);
		else if (read_status == 0)
		{
			*(*lineptr + read_bytes) = '\0';
			break ;
		}
		read_bytes++;
		if (*(*lineptr + (read_bytes - 1)) == '\n')
		{
			*(*lineptr + read_bytes) = '\0';
			break ;
		}
	}
	return (read_bytes);
}

#undef FOR_NULL_TERM
#undef JUST_ONE_BYTE

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (!n)
	{
		return (0);
	}
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && --n)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
