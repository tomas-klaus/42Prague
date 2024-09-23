/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:08:15 by dmalasek          #+#    #+#             */
/*   Updated: 2024/08/28 15:13:37 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	is_same_line_length(char *filename)
{
	int	i;
	int	first_line_length;
	int	current_line_length;

	first_line_length = get_line_length(1, filename);
	if (first_line_length <= 0)
		return (0);
	i = 1;
	while (i < get_number_of_lines(filename) - 1)
	{
		current_line_length = get_line_length(i, filename);
		if (current_line_length != first_line_length)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_obstacle_present(char *filename)
{
	int		file;
	char	c;
	int		i;
	char	obstacle_character;
	char	current_line;

	file = open_file(filename);
	current_line = 0;
	i = 0;
	while (read(file, &c, 1) > 0)
	{
		if (c == '\n')
			current_line++;
		if (i == get_line_length(0, filename) - 2 && current_line == 0)
			obstacle_character = c;
		if (c == obstacle_character && current_line != 0)
		{
			close(file);
			return (1);
		}
		i++;
	}
	close(file);
	return (0);
}

int	is_first_line_valid(char *filename)
{
	int		file;
	char	c;
	int		i;
	int		e;
	char	characters[3];

	file = open_file(filename);
	i = 0;
	e = 0;
	while (read(file, &c, 1) > 0)
	{
		if (c == '\n')
			break ;
		if ((i < get_line_length(0, filename) - 4) && (c < '0' || c > '9'))
			return (0);
		if (i >= get_line_length(0, filename) - 3 && i <= get_line_length(0,
				filename) - 1)
			characters[e++] = c;
		i++;
	}
	close(file);
	return (characters[0] != characters[1] && characters[0] != characters[2]
		&& characters[1] != characters[2] && i >= 4);
}

int	is_correct_lines(char *filename)
{
	int		file;
	char	c;
	int		i;
	char	*row_num_str;

	row_num_str = malloc(get_line_length(0, filename) - 3);
	i = 0;
	file = open_file(filename);
	while (read(file, &c, 1) > 0)
	{
		if (i <= get_line_length(0, filename) - 4)
			row_num_str[i] = c;
		i++;
	}
	return (ft_atoi(row_num_str) == get_number_of_lines(filename) - 1);
}

int	are_map_chars_valid(char *filename)
{
	int		file;
	char	empty_char;
	char	obstacle_char;
	char	c;
	int		current_line;

	file = open_file(filename);
	obstacle_char = get_char_on_index(get_line_length(0, filename) - 2,
			filename);
	empty_char = get_char_on_index(get_line_length(0, filename) - 3, filename);
	current_line = 0;
	while (read(file, &c, 1) > 0)
	{
		if (c == '\n')
			current_line++;
		else if (current_line != 0 && c != obstacle_char && c != empty_char)
		{
			close(file);
			return (0);
		}
	}
	close(file);
	return (1);
}
