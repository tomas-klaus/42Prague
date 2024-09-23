/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:36:21 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/28 20:20:25 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	draw_square(int **matrix, struct s_MaxInfo max_info, int value)
{
	int	lower_right_row;
	int	lower_right_col;
	int	side_length;
	int	i;
	int	j;

	lower_right_row = max_info.row;
	lower_right_col = max_info.col;
	side_length = max_info.value;
	i = lower_right_row - side_length + 1;
	while (i <= lower_right_row)
	{
		j = lower_right_col - side_length + 1;
		while (j <= lower_right_col)
		{
			matrix[i][j] = value;
			j++;
		}
		i++;
	}
}

void	putchar_custom(char c)
{
	write(1, &c, 1);
}

int	render_square(struct s_map map, int **dp_matrix, int box_value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map.row_num)
	{
		j = 0;
		while (j < map.col_num)
		{
			if (dp_matrix[i][j] == 0)
				putchar_custom(map.obstacle);
			else if (dp_matrix[i][j] == box_value)
				putchar_custom(map.full);
			else
				putchar_custom(map.empty);
			j++;
		}
		putchar_custom('\n');
		i++;
	}
	return (0);
}

int	write_square(struct s_MaxInfo max_info, struct s_map map, int **dp_matrix)
{
	draw_square(dp_matrix, max_info, max_info.value + 1);
	render_square(map, dp_matrix, max_info.value + 1);
	return (0);
}
