/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:40 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/12 20:26:58 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
Take two arguments
+open and read the file
+make the whole thing with the buffer and reallocing
+Check file name if it is .ber

+Parse Map
{argv[1] is the map and it is a string
take the string and check for
	Is it not empty
	If all lines are same length
then make it into a 2D array and check
	Is the map enclosed in walls
	Is there only one exit
	Is there only one start position
	Is there at least one collectible
Check if exit is accesible from start and if all collectibles are accesible
flood fill algorithm
	if the exit hasnt been reached return 0
	else return the number of collectibles
}

Game
{Create a window using MiniLibX
	Create the required structure to store all the necessary information
Load all the required sprites (images) for your game and store them into memory
Create the different hooks
	key_handler
	close_handler,
		this is a hook on the red cross that closes the program correctly
	loop_hook (=> my game loop)}

Render checklist
{Draw the background
Draw the not movable parts of the map
Draw the player}

Key handler
{Is the requested new position a Wall ?
	if the new position is a Wall,
		don't do anything. The subject says that the player should not be able to go through walls
Is the requested new position inside the map ?
	if the new position is outside the map,
		don't do anything. Normally this shouldn't happen since the map is enclosed in walls but hey,
		never too sure.
Is the requested new position a Collectible ?
	if yes, update the collected items counter and check
	check if all collectibles have been collected
		if yes, unlock the exit
	update your map 2D array and replace the collectible by a "floor" tile so that it is not drawn in the next iteration of the game loop.
If the requested new position is not a wall, nor a collectible,
	nor outside the map,
	simply set the player position to the requested new position.}
 */

int	main(int argc, char **argv)
{
	char	*strmap;
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long <map_file>\n");
		return (1);
	}
	strmap = read_file(argv[1]);
	if (!strmap)
		return (1);
	if (!parse_map(strmap, &data))
	{
		free(strmap);
		ft_printf("Error\n");
		return (1);
	}
	graphics(&data);
	return (0);
}
