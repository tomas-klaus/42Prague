/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:50:20 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/11/13 12:53:22 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42
#  define GET_NEXT_LINE_H

#  include <stdio.h>
#  include <stdlib.h>
#  include <unistd.h>

char	*get_next_line(int fd);

void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char *s2);
size_t	ft_strlen(const char *str);

# endif
#endif
