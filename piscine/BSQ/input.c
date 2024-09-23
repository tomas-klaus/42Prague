/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:44:01 by dmalasek          #+#    #+#             */
/*   Updated: 2024/08/28 15:05:04 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	read_first_line(char *buffer, int *n_lines, char *chars)
{
	ssize_t	bytes_read;
	int		first_line_len;

	bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
	if (bytes_read < 0)
		throw_error();
	buffer[bytes_read] = '\0';
	first_line_len = str_len(buffer);
	if (first_line_len < 4)
		throw_error();
	chars[0] = buffer[first_line_len - 3];
	chars[1] = buffer[first_line_len - 2];
	chars[2] = buffer[first_line_len - 1];
	buffer[first_line_len - 3] = '\0';
	*n_lines = ft_atoi(buffer);
	if (*n_lines <= 0)
		throw_error();
}

void	read_line(char **line, size_t *line_len)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
		if (bytes_read < 0)
			throw_error();
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		append_buffer(line, line_len, buffer, (size_t)bytes_read);
		if (buffer[bytes_read - 1] == '\n')
			break ;
	}
	if (*line_len > 0 && (*line)[*line_len - 1] == '\n')
		(*line_len)--;
}

void	read_lines(int n_lines, char **lines, size_t *total_len)
{
	char	*line;
	size_t	line_len;
	int		first_line_added;

	first_line_added = 0;
	while (n_lines-- > 0)
	{
		line = NULL;
		line_len = 0;
		read_line(&line, &line_len);
		if (first_line_added)
			append_buffer(lines, total_len, "\n", 1);
		append_buffer(lines, total_len, line, line_len);
		free(line);
		first_line_added = 1;
	}
}

char	*read_input(void)
{
	char	buffer[BUFFER_SIZE];
	char	*lines;
	int		n_lines;
	char	chars[3];
	size_t	total_len;

	lines = malloc(1);
	total_len = 0;
	if (lines == NULL)
		throw_error();
	lines[0] = '\0';
	read_first_line(buffer, &n_lines, chars);
	append_buffer(&lines, &total_len, buffer, str_len(buffer));
	append_buffer(&lines, &total_len, chars, 3);
	read_lines(n_lines, &lines, &total_len);
	write_to_file("output", lines, total_len);
	free(lines);
	return ("output");
}
