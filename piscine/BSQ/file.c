/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:56:34 by dmalasek          #+#    #+#             */
/*   Updated: 2024/08/28 15:03:10 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	append_buffer(char **line, size_t *line_len, const char *buffer,
		size_t bytes_read)
{
	char	*new_line;
	size_t	i;

	new_line = ft_realloc(*line, *line_len + bytes_read + 1);
	if (new_line == NULL)
		throw_error();
	*line = new_line;
	i = 0;
	while (i < bytes_read)
	{
		(*line)[*line_len + i] = buffer[i];
		i++;
	}
	*line_len += bytes_read;
	(*line)[*line_len] = '\0';
}

void	write_to_file(const char *filename, const char *content,
		size_t content_len)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		throw_error();
	write(fd, content, content_len);
	close(fd);
}
