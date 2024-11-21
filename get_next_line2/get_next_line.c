/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:17:12 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/11/21 13:48:02 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 	Finds the '\n' symbol in buffer and copies only the characters
	after that into a new buffer */

char	*get_next(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), buffer = NULL, NULL);
	new_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!new_buffer)
		return (free(buffer), buffer = NULL, NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	return (free(buffer), buffer = NULL, new_buffer);
}

/* 	Locates the '\n' character in buffer and copies only characters
	before and including it into a new buffer line
	If there is no '\n', it copies the whole buffer into line.
	*/

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (free(buffer), buffer = NULL, NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/* 	Reads the file by small BUFFER_SIZE chunks and adds them
	to the static_buffer.
	When the '\n' character is located, it breaks the loop, frees
	the chunk_buffer and returns static_buffer */

char	*read_to_buffer(int fd, char *static_buffer)
{
	char	*chunk_buffer;
	int		bytes_read;

	if (!static_buffer)
		static_buffer = ft_calloc(1, 1);
	if (!static_buffer)
		return (NULL);
	chunk_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!chunk_buffer)
		return (free(static_buffer), static_buffer = NULL, NULL);
	while (1)
	{
		bytes_read = read(fd, chunk_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(chunk_buffer), free(static_buffer),
				static_buffer = NULL, NULL);
		chunk_buffer[bytes_read] = '\0';
		static_buffer = ft_strjoin(static_buffer, chunk_buffer);
		if (!static_buffer)
			return (free(static_buffer), static_buffer = NULL, NULL);
		if (ft_strchr(chunk_buffer, '\n') || bytes_read < BUFFER_SIZE)
			break ;
	}
	free(chunk_buffer);
	return (static_buffer);
}

/* 	The main function that reads the file and returns the line.
	First,it fills the buffer with BUFFER_SIZEd chunks of data
	by reading from fd, doesnt matter if it goes past the '\n'.

	Then, it extracts only the first line from the buffer and fills
	line with the data.

	Finally, it leaves in the buffer only the remaining data
	after the '\n' for the next call of the function.
*/

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	line = extract_line(buffer);
	if (!line)
		return (buffer = NULL, NULL);
	buffer = get_next(buffer);
	if (!buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

/* #include <fcntl.h>

int	main(void)
{
	int fd;
	char *line;
	int i = 0;

	fd = open("giant_line.txt", O_RDONLY);
	while (i < 1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);

	return (0);
} */