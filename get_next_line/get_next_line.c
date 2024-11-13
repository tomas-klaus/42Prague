/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:49:32 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/11/13 11:13:03 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	read_to_buffer(int fd, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	return (bytes_read);
}

static char	*append_to_line(char *line, char *buffer, ssize_t bytes_to_copy)
{
	char	*new_line;
	int		len;

	if (!line)
	{
		new_line = malloc(bytes_to_copy + 1);
		if (!new_line)
			return (NULL);
		ft_memcpy(new_line, buffer, bytes_to_copy);
		new_line[bytes_to_copy] = '\0';
	}
	else
	{
		len = ft_strlen(line);
		new_line = ft_realloc_str(line, len, len + bytes_to_copy + 1);
		if (!new_line)
			return (NULL);
		ft_strlcat(new_line, buffer, len + bytes_to_copy + 1);
	}
	return (new_line);
}

static ssize_t	find_newline(char *buffer, ssize_t bytes_read)
{
	char	*newline_pos;

	newline_pos = ft_memchr(buffer, '\n', bytes_read);
	if (newline_pos)
		return (newline_pos - buffer + 1);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	bytes_read = 0;
	static ssize_t	buffer_pos = 0;
	char			*line;
	ssize_t			bytes_to_copy;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (line);
	while (1)
	{
		if (buffer_pos >= bytes_read)
		{
			bytes_read = read_to_buffer(fd, buffer);
			buffer_pos = 0;
			if (bytes_read <= 0)
				return (line);
		}
		bytes_to_copy = find_newline(buffer + buffer_pos, bytes_read
				- buffer_pos);
				//printf("bytes_to_copy: %ld\n", bytes_to_copy);
		line = append_to_line(line, buffer + buffer_pos, bytes_to_copy);
		buffer_pos += bytes_to_copy;
		if (buffer_pos < bytes_read || bytes_read < BUFFER_SIZE)
			return (line);
	}
}

#include <fcntl.h>

int	main(void)
{
	int fd;
	char *line;
	int i = 0;

	fd = open("test.txt", O_RDONLY);
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	return (0);
}