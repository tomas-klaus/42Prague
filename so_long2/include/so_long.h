/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:59:50 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/14 12:56:42 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h> // For open()
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> // For close()

# define BUFFER_SIZE 1024
# define IMG_SIZE 32

# define DESTROY_NOTIFY 17
# ifdef __APPLE__
#  define ESC_KEY 53
#  define UP_KEY 126
#  define DOWN_KEY 125
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
#  define W_KEY 13
#  define S_KEY 1
#  define A_KEY 0
#  define D_KEY 2
# elif __linux__
#  define ESC_KEY 65307
#  define UP_KEY 65362
#  define DOWN_KEY 65364
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
#  define W_KEY 119
#  define S_KEY 115
#  define A_KEY 97
#  define D_KEY 100
# endif

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
int			count_items(char **map, int row, int column, int counts[3]);
void		deinit(t_data data);

#endif