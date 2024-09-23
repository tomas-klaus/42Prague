/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:37:44 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/28 20:11:48 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	free_matrix(int **matrix, int row_size)
{
	int	i;

	i = 0;
	while (i < row_size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (0);
}

int	**allocate_matrix(int row_size, int column_size)
{
	int	**matrix;
	int	i;

	matrix = (int **)malloc(sizeof(int *) * row_size);
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < row_size)
	{
		matrix[i] = (int *)malloc(sizeof(int) * column_size);
		if (matrix[i] == NULL)
		{
			while (--i >= 0)
			{
				free(matrix[i]);
			}
			free(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

int	solve_map(struct s_map map)
{
	int					i;
	int					fd;
	int					**matrix;
	int					**dp_matrix;
	struct s_MaxInfo	max_info;

	i = 0;
	fd = open_file(map.filename);
	matrix = allocate_matrix(3, count_obstacles(fd, map));
	close(fd);
	fd = open_file(map.filename);
	fill_matrix(matrix, fd, map);
	close(fd);
	dp_matrix = allocate_matrix(map.row_num, map.col_num);
	find_square(matrix, dp_matrix, map);
	max_info = find_max_in_matrix(dp_matrix, map.row_num, map.col_num);
	write_square(max_info, map, dp_matrix);
	free_matrix(matrix, 3);
	free_matrix(dp_matrix, map.row_num);
	return (0);
}
