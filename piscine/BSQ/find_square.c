/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:14:07 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/28 19:15:07 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	is_obstacle(int **matrix, int row, int col)
{
	int	k;

	k = 0;
	while (matrix[0][k] != 0)
	{
		if (matrix[1][k] == row && matrix[2][k] == col)
		{
			return (1);
		}
		k++;
	}
	return (0);
}

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

int	first_row_col(int **matrix, int **dp_matrix, int row_size, int column_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row_size)
	{
		if (is_obstacle(matrix, i, j))
			dp_matrix[i][0] = 0;
		else
			dp_matrix[i][0] = 1;
		i++;
	}
	i = 0;
	while (j < column_size)
	{
		if (is_obstacle(matrix, i, j))
			dp_matrix[0][j] = 0;
		else
			dp_matrix[0][j] = 1;
		j++;
	}
	return (0);
}

void	fillmatrix_sq(int **matrix, int **dp_matrix, int row_size,
		int column_size)
{
	int	i;
	int	j;

	first_row_col(matrix, dp_matrix, row_size, column_size);
	i = 1;
	while (i < row_size)
	{
		j = 1;
		while (j < column_size)
		{
			if (is_obstacle(matrix, i, j))
				dp_matrix[i][j] = 0;
			else
			{
				dp_matrix[i][j] = min(dp_matrix[i - 1][j], dp_matrix[i][j - 1],
						dp_matrix[i - 1][j - 1]) + 1;
			}
			j++;
		}
		i++;
	}
}

int	find_square(int **matrix, int **dp_matrix, struct s_map map)
{
	int	row_size;
	int	column_size;

	row_size = map.row_num;
	column_size = map.col_num;
	fillmatrix_sq(matrix, dp_matrix, row_size, column_size);
	return (0);
}
