/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:56:15 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/01/07 13:04:26 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 1000
#define RADIUS 50

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_circle
{
	int		x;
	int		y;
	int		color;
}			t_circle;

t_circle	circle = {WIDTH / 2, HEIGHT / 2, 0x00FF0000};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_circle(t_data *img, t_circle *circle)
{
	int x, y;
	for (y = -RADIUS; y <= RADIUS; y++)
	{
		for (x = -RADIUS; x <= RADIUS; x++)
		{
			if (x * x + y * y <= RADIUS * RADIUS)
				my_mlx_pixel_put(img, circle->x + x, circle->y + y,
					circle->color);
		}
	}
}

int	render_next_frame(t_data *img, t_vars *vars)
{
	// Clear the image
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			my_mlx_pixel_put(img, x, y, 0x00000000);
		}
	}
	// Draw the circle
	draw_circle(img, &circle);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	return (0);
}

int	key_hook(int keycode)
{
	if (keycode == 53) // Assuming 53 is the keycode for the escape key
		exit(0);
	else if (keycode == 13) // W key
		circle.y -= 100;
	else if (keycode == 1) // S key
		circle.y += 100;
	else if (keycode == 0) // A key
		circle.x -= 100;
	else if (keycode == 2) // D key
		circle.x += 100;
	return (0);
}

int	main(void)
{
	t_vars vars;
	t_data img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	mlx_key_hook(vars.win, key_hook, NULL);

	mlx_loop_hook(vars.mlx, (int (*)())render_next_frame, &img);

	mlx_loop(vars.mlx);
}