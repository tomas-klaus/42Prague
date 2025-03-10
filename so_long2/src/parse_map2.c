/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:48:37 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/10 23:13:27 by tomasklaus       ###   ########.fr       */
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
		{
			ft_printf("Error: Map is not enclosed in walls\n");
			return (0);
		}
		i++;
	}
	while (j < column)
	{
		if (map[0][j] != '1' || map[row - 1][j] != '1')
		{
			ft_printf("Error: Map is not enclosed in walls\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_items(char **map, int row, int column)
{
	int	i;
	int	j;
	int	counts[3] = {0, 0, 0};

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
	if (counts[0] != 1 || counts[2] != 1 || counts[1] == 0)
	{
		ft_printf("Error: Map is missing items\n");
		return (0);
	}
	return (counts[1]);
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
	;
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
		ft_printf("Error: Exit is not reachable\n");
		return (0);
	}
	return (collectible);
}

int	validate_map(char **map, int row, int column, t_data *data)
{
	int	start[2] = {0, 0};
	int	reachable;

	if (!check_walls(map, row, column))
		return (0);
	ft_printf("Walls OK\n");
	data->map.collectibles = check_items(map, row, column);
	ft_printf("Collectibles: %d\n", data->map.collectibles);
	if (!data->map.collectibles)
		return (0);
	find_player(map, row, column, start);
	ft_printf("Player: Row %d, Column %d\n", start[0], start[1]);
	data->p_row = start[0];
	data->p_col = start[1];
	reachable = flood_fill(map, start[0], start[1]);
	ft_printf("Reachable collectibles: %d\n", reachable);
	if (!reachable || !(data->map.collectibles == reachable))
		return (0);
	ft_printf("Map is valid\n");
	return (1);
}
