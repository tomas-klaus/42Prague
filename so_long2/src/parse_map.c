/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:41:40 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/14 14:20:04 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_2d_array(char **array, int rows)
{
    int i = 0;
    while (i < rows)
    {
        free(array[i]);
        i++;
    }
    free(array);
}

int	check_lines(char *str)
{
	int	i;
	int	line;
	int	j;

	i = 0;
	line = 0;
	if (!str || str[0] == '\n')
		return (0);
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] != '\n')
		{
			i++;
			j++;
		}
		if (line && line != j)
			return (0);
		line = j;
		if (str[i] && str[i + 1])
			i++;
	}
	return (line);
}

char	**fill_map(char **map, int rows, int columns, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < rows)
	{
		while (j < columns)
		{
			map[i][j] = str[k];
			j++;
			k++;
		}
		map[i][j] = '\0';
		j = 0;
		i++;
		k++;
	}
	return (map);
}

char	**malloc_map(int rows, int columns, char *str)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(rows * sizeof(char *));
	if (!map)
		return (0);
	while (i < rows)
	{
		map[i] = malloc(columns + 1 * sizeof(char));
		if (!map[i])
		{
			free_2d_array(map, i);
			return (0);
		}
		i++;
	}
	map = fill_map(map, rows, columns, str);
	return (map);
}

int	parse_map(char *str, t_data *data)
{
	data->map.columns = check_lines(str);
	if (!data->map.columns){
		ft_printf("Error: Map is not rectangular\n");
		return (0);
	}
		
	data->map.rows = ft_strlen(str) / data->map.columns;
	data->map.map = malloc_map(data->map.rows, data->map.columns, str);
	if (!data->map.map)
		return (0);
	if (!validate_map(data->map.map, data->map.rows, data->map.columns, data))
		return (0);
	free_2d_array(data->map.map, data->map.rows);
	data->map.map = malloc_map(data->map.rows, data->map.columns, str);
	if (!data->map.map)
		return (0);
	return (1);
}
