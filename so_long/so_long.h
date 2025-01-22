/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:59:50 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/01/20 13:37:18 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h> // For open()
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> // For close()

# define BUFFER_SIZE 1024
# define IMG_SIZE 32

typedef struct s_map
{
	int		rows;
	int		columns;
	char	**map;
	int		collectibles;
}			t_map;

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
	void	*wall;
	void	*exit;
	void	*empty;
	void	*player;
	void	*col;

}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		p_row;
	int		p_col;
	t_map	map;
	t_img	img;
}			t_data;

char		*read_file(char *filename);
int			parse_map(char *str, t_data *data);
int			validate_map(char **map, int x, int y, t_data *data);
void		graphics(t_data *data);
int			hooks(t_data *data);
int			render(t_data *data);

#endif