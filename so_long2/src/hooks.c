/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:15:11 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/14 14:05:28 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	col_checker(t_data *data)
{
	if (data->map.map[data->p_row][data->p_col] == 'C')
	{
		data->map.map[data->p_row][data->p_col] = '0';
		data->map.collectibles -= 1;
	}
	if (data->map.map[data->p_row][data->p_col] == 'E'
		&& data->map.collectibles == 0)
	{
		mlx_destroy_window(data->mlx, data->win);
		deinit(*data);
		ft_printf("You won!\n");
		exit(0);
	}
}

void	move_print(int keycode, t_data *data)
{
	static int	moves = 1;

	if (keycode == UP_KEY || keycode == W_KEY)
		if (data->map.map[data->p_row - 1][data->p_col] != '1')
			ft_printf("Moves: %d\n", moves++);
	if (keycode == DOWN_KEY || keycode == S_KEY)
		if (data->map.map[data->p_row + 1][data->p_col] != '1')
			ft_printf("Moves: %d\n", moves++);
	if (keycode == LEFT_KEY || keycode == A_KEY)
		if (data->map.map[data->p_row][data->p_col - 1] != '1')
			ft_printf("Moves: %d\n", moves++);
	if (keycode == RIGHT_KEY || keycode == D_KEY)
		if (data->map.map[data->p_row][data->p_col + 1] != '1')
			ft_printf("Moves: %d\n", moves++);
}

int	key_handler(int keycode, t_data *data)
{
	move_print(keycode, data);
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(data->mlx, data->win);
		deinit(*data);
		exit(0);
	}
	if (keycode == UP_KEY || keycode == W_KEY)
		if (data->map.map[data->p_row - 1][data->p_col] != '1')
			data->p_row -= 1;
	if (keycode == DOWN_KEY || keycode == S_KEY)
		if (data->map.map[data->p_row + 1][data->p_col] != '1')
			data->p_row += 1;
	if (keycode == LEFT_KEY || keycode == A_KEY)
		if (data->map.map[data->p_row][data->p_col - 1] != '1')
			data->p_col -= 1;
	if (keycode == RIGHT_KEY || keycode == D_KEY)
		if (data->map.map[data->p_row][data->p_col + 1] != '1')
			data->p_col += 1;
	col_checker(data);
	mlx_clear_window(data->mlx, data->win);
	render(data);
	return (0);
}

int	close_handler(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	deinit(*data);
	
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
