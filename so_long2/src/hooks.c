/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:15:11 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/02 17:34:23 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_handler(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == 126 || keycode == 13)
		if (data->map.map[data->p_row - 1][data->p_col] != '1')
			data->p_row -= 1;
	if (keycode == 125 || keycode == 1)
		if (data->map.map[data->p_row + 1][data->p_col] != '1')
			data->p_row += 1;
	if (keycode == 123 || keycode == 0)
		if (data->map.map[data->p_row][data->p_col - 1] != '1')
			data->p_col -= 1;
	if (keycode == 124 || keycode == 2)
		if (data->map.map[data->p_row][data->p_col + 1] != '1')
			data->p_col += 1;
	if (data->map.map[data->p_row][data->p_col] == 'C')
		data->map.map[data->p_row][data->p_col] = '0';
	mlx_clear_window(data->mlx, data->win); // Clear the window before redrawing
	render(data);
	return (0);
}

int	close_handler(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_handler, data);
	mlx_hook(data->win, 17, 1L << 17, close_handler, data);
	mlx_loop(data->mlx);
	return (0);
}