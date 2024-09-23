/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:04:30 by dmalasek          #+#    #+#             */
/*   Updated: 2024/08/28 20:14:10 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	validate_map(char *filename)
{
	if (open_file(filename) == -1)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	if (!(is_same_line_length(filename) && is_obstacle_present(filename)
			&& is_first_line_valid(filename) && is_correct_lines(filename)
			&& are_map_chars_valid(filename)))
	{
		write(1, "map error\n", 10);
		return (0);
	}
	return (1);
}

struct s_map	setup(char *filename)
{
	struct s_map	map;

	map.row_num = get_number_of_lines(filename) - 1;
	map.col_num = get_line_length(1, filename);
	map.empty = get_char_on_index(get_line_length(0, filename) - 3, filename);
	map.obstacle = get_char_on_index(get_line_length(0, filename) - 2,
			filename);
	map.full = get_char_on_index(get_line_length(0, filename) - 1, filename);
	map.filename = filename;
	return (map);
}
