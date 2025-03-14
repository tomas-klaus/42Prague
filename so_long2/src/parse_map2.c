/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:48:37 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/14 14:25:58 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_walls(char **map, int row, int column)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row)
	{
		if (map[i][0] != '1' || map[i][column - 1] != '1')
			return (0);
		i++;
	}
	while (j < column)
	{
		if (map[0][j] != '1' || map[row - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_items(char **map, int row, int column)
{
	int	counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	count_items(map, row, column, counts);
	if (counts[0] == 1 && counts[2] == 1 && counts[1] > 0)
		return (counts[1]);
	if (counts[0] == -1)
		ft_printf("Error: Invalid character in map\n");
	if (counts[0] == 0)
		ft_printf("Error: No exit found\n");
	if (counts[0] > 1)
		ft_printf("Error: Multiple exits found\n");
	if (counts[2] == 0)
		ft_printf("Error: No player found\n");
	if (counts[2] > 1)
		ft_printf("Error: Multiple players found\n");
	if (counts[1] < 1)
		ft_printf("Error: Missing collectibles\n");
	return (0);
}

void	find_player(char **map, int row, int column, int start[2])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if (map[i][j] == 'P')
			{
				start[0] = i;
				start[1] = j;
			}
			j++;
		}
		i++;
	}
}

int	flood_fill(char **map, int row, int column)
{
	static int	exit = 0;
	static int	collectible = 0;
	char		wall;

	wall = '1';
	if (map[row][column] == wall)
		return (0);
	if (map[row][column] == 'E')
		exit++;
	if (map[row][column] == 'C')
		collectible++;
	map[row][column] = wall;
	flood_fill(map, row - 1, column);
	flood_fill(map, row, column + 1);
	flood_fill(map, row + 1, column);
	flood_fill(map, row, column - 1);
	if (!exit)
	{
		return (0);
	}
	return (collectible);
}

int	validate_map(char **map, int row, int column, t_data *data)
{
	int	start[2];
	int	reachable;

	start[0] = 0;
	start[1] = 0;
	if (!check_walls(map, row, column))
	{
		ft_printf("Error: Map is not enclosed in walls\n");
		return (0);
	}
	if (0 == (data->map.collectibles = check_items(map, row, column)))
		return (0);
	find_player(map, row, column, start);
	data->p_row = start[0];
	data->p_col = start[1];
	reachable = flood_fill(map, start[0], start[1]);
	if (!reachable || !(data->map.collectibles == reachable))
	{
		ft_printf("Error: Not a valid path\n");
		return (0);
	}
	return (1);
}
