/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:50:20 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/11/13 11:13:30 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1
#  define GET_NEXT_LINE_H

#  include <stdio.h>
#  include <stdlib.h>
#  include <unistd.h>

char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_realloc_str(char *str, unsigned int old_buff_size,
			unsigned int new_buff_size);

size_t	read_one_buffer(int fd, char *buffer);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);

# endif
#endif
