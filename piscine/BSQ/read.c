/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:56:58 by dmalasek          #+#    #+#             */
/*   Updated: 2024/08/28 15:01:22 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	open_file(char *filename)
{
	int	file;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return (-1);
	return (file);
}

int	read_line_length(int file, int target_line)
{
	int		current_line;
	int		line_length;
	char	c;

	current_line = 0;
	current_line = 0;
	line_length = 0;
	while (read(file, &c, 1) > 0)
	{
		if (c == '\n')
		{
			if (current_line == target_line)
				return (line_length);
			current_line++;
			line_length = 0;
		}
		else if (current_line == target_line)
			line_length++;
	}
	if (current_line == target_line)
		return (line_length);
	return (0);
}

int	get_line_length(int row_num, char *filename)
{
	int	file;
	int	line_length;

	file = open_file(filename);
	line_length = read_line_length(file, row_num);
	close(file);
	return (line_length);
}

int	get_number_of_lines(char *filename)
{
	int		file;
	char	c;
	int		number_of_nl;

	file = open_file(filename);
	number_of_nl = 0;
	while (read(file, &c, 1) > 0)
	{
		if (c == '\n')
			number_of_nl++;
	}
	close(file);
	return (number_of_nl + 1);
}

char	get_char_on_index(int index, char *filename)
{
	int		file;
	char	c;
	int		i;

	file = open_file(filename);
	i = 0;
	while (read(file, &c, 1) > 0)
	{
		if (i == index)
			return (c);
		i++;
	}
	close(file);
	return ('\0');
}
