/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:59:22 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/01/22 12:39:21 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	load_textures(t_data *data)
{
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
			&data->img.width, &data->img.height);
	if (!data->img.wall)
		return (1); // Failed to load texture
	data->img.empty = mlx_xpm_file_to_image(data->mlx, "textures/empty.xpm",
			&data->img.width, &data->img.height);
	if (!data->img.empty)
		return (1); // Failed to load texture
	data->img.player = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm",
			&data->img.width, &data->img.height);
	if (!data->img.player)
		return (1); // Failed to load texture
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm",
			&data->img.width, &data->img.height);
	if (!data->img.exit)
		return (1); // Failed to load texture
	data->img.col = mlx_xpm_file_to_image(data->mlx, "textures/collectible.xpm",
			&data->img.width, &data->img.height);
	if (!data->img.col)
		return (1); // Failed to load texture
	return (0);
}
void	put_imgs(t_data *data, int width, int i, int j)
{
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, width, i
			* IMG_SIZE);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.empty, width, i
			* IMG_SIZE);
	/* else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			width, i * IMG_SIZE); */
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit, width, i
			* IMG_SIZE);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.col, width, i
			* IMG_SIZE);
	if (i == data->p_row && j == data->p_col)
		mlx_put_image_to_window(data->mlx, data->win, data->img.player, width, i
			* IMG_SIZE);
}

int	render(t_data *data)
{
	int	i;
	int	j;
	int	width;

	if (data->win == NULL)
		return (0);
	i = 0;
	j = 0;
	width = 0;
	while (i < data->map.rows)
	{
		while (i < data->map.rows && j < data->map.columns)
		{
			put_imgs(data, width, i, j);
			width += IMG_SIZE;
			j++;
		}
		j = 0;
		width = 0;
		i++;
	}
	printf("Player: %d %d\n", data->p_row, data->p_col);
	return (1);
}

void	graphics(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->map.columns * IMG_SIZE),
			(data->map.rows * IMG_SIZE), "so_long");
	if (load_textures(data))
	{
		printf("Failed to load textures\n");
		exit(1);
	}
	printf("Textures loaded\n");
	render(data);
	printf("Map rendered\n");
	hooks(data);
	printf("Hooks set\n");
	mlx_loop(data->mlx);
}
