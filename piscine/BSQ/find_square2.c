/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:38:24 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/28 19:59:36 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

struct s_MaxInfo	find_max_in_matrix(int **matrix, int row_size,
		int column_size)
{
	struct s_MaxInfo	max_info;
	int					i;
	int					j;

	max_info.value = matrix[0][0];
	max_info.row = 0;
	max_info.col = 0;
	i = 0;
	while (i < row_size)
	{
		j = 0;
		while (j < column_size)
		{
			if (matrix[i][j] > max_info.value)
			{
				max_info.value = matrix[i][j];
				max_info.row = i;
				max_info.col = j;
			}
			j++;
		}
		i++;
	}
	return (max_info);
}
