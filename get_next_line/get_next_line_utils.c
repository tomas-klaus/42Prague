/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:50:23 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/10/17 17:56:02 by tklaus           ###   ########.fr       */
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
size_t	ft_strlen(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (0);
	dst_len = 0;
	src_len = 0;
	i = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] != '\0' && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
