/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:59:27 by dmalasek          #+#    #+#             */
/*   Updated: 2024/08/28 20:11:33 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	process_file(char *filename)
{
	struct s_map	map;

	if (validate_map(filename))
	{
		map = setup(filename);
		solve_map(map);
	}
}

void	process_input(int argc, char *argv[])
{
	int		i;
	char	*filename;

	i = 1;
	if (argc == 1)
	{
		filename = read_input();
		process_file(filename);
	}
	else
	{
		while (i < argc)
		{
			process_file(argv[i]);
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	process_input(argc, argv);
	return (0);
}
