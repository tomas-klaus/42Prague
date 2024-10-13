/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:50:23 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/10/11 15:31:26 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
        //printf("new_buff[%d]: %c\n", i, new_buff[i]);
		i++;
	}
	new_buff[i] = '\0';
	//free(str);
	return (new_buff);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;

	if (!src || !dest)
		return (dest);
	i = 0;
	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (dest);
}
