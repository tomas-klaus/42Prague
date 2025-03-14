/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:16:17 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/14 12:16:22 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_items(char **map, int row, int column, int counts[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if (map[i][j] == 'E')
				counts[0]++;
			else if (map[i][j] == 'C')
				counts[1]++;
			else if (map[i][j] == 'P')
				counts[2]++;
			else if (!(map[i][j] == '1' || map[i][j] == '0'))
				counts[0] = 2;
			j++;
		}
		i++;
	}
	return (counts[0] != 1 || counts[2] != 1 || counts[1] == 0);
}