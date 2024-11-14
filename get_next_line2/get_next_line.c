/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:17:12 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/11/14 11:44:13 by tklaus           ###   ########.fr       */
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
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

/* 	Locates the '\n' character in buffer and copies only characters
	before and including it into a new buffer line */

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

/* 	Reads the file by small BUFFER_SIZE chunks and adds them to the full.
	When the '\n' character is located, it breaks the loop, frees
	the buffer and returns full */

char	*read_to_buffer(int fd, char *full)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	if (!full)
		full = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		full = ft_strjoin(full, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (full);
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
		return (NULL);
	line = extract_line(buffer);
	buffer = get_next(buffer);
	return (line);
}
/*
#include <fcntl.h>

int	main(void)
{
	int fd;
	char *line;
	int i = 0;

	fd = open("read_error.txt", O_RDONLY);
	printf("first call \n------------------------------------\n");
	while (i < 2)
	{
		line = get_next_line(fd);
		//printf("%s", line);
		free(line);
		i++;
	}
	printf("------------------------------------\n\n");
	close(fd);
	fd = -10;
	i = 0;

	printf("second call \n------------------------------------\n");
	while (i < 1)
	{
		line = get_next_line(fd);
		//printf("%s", line);
		free(line);
		i++;
	}
	printf("------------------------------------\n\n");
	fd = open("read_error.txt", O_RDONLY);
	i = 0;
	printf("third call \n------------------------------------\n");
	while (i < 4)
	{
		line = get_next_line(fd);
		//printf("%s", line);
		free(line);
		i++;
	}
	printf("------------------------------------\n");
	return (0);
} */