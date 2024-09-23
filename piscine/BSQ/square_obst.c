/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_obst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:05:12 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/28 20:13:34 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	count_obstacles(int fd, struct s_map map)
{
	char	c;
	int		o_count;
	int		firstline;

	o_count = 0;
	firstline = 1;
	while (read(fd, &c, 1) > 0)
	{
		if (c == map.obstacle)
		{
			o_count++;
		}
		if (c == '\n' && firstline == 1)
		{
			firstline = 0;
			o_count = 0;
		}
	}
	return (o_count);
}

void	handle_obstacle(int **matrix, int row, int column, int *obstacle)
{
	matrix[0][*obstacle - 1] = *obstacle;
	matrix[1][*obstacle - 1] = row;
	matrix[2][*obstacle - 1] = column;
	(*obstacle)++;
}

void	process_file_data(int **matrix, int fd, struct s_map map)
{
	char	c;
	int		firstline;
	int		column;
	int		row;
	int		obstacle;

	firstline = 1;
	column = 0;
	row = 0;
	obstacle = 1;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			if (firstline)
				firstline = 0;
			else
				row++;
			column = -1;
		}
		else if (!firstline && c == map.obstacle)
			handle_obstacle(matrix, row, column, &obstacle);
		column++;
	}
}

int	fill_matrix(int **matrix, int fd, struct s_map map)
{
	process_file_data(matrix, fd, map);
	return (0);
}
