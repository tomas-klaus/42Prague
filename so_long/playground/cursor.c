/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:40:57 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/01/07 14:42:57 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

#include <stdlib.h>

typedef struct s_vars {
    void    *mlx;
    void    *win;
    void    *img;
    int     x, y; // Coordinates for the image
    int     img_width, img_height;
}   t_vars;

int key_hook(int keycode)
{
    // Check if the escape key is pressed
    if (keycode == 53) // 53 is the keycode for the escape key
        exit(0);
    return (0);
}
int mouse_hook(int x, int y, t_vars *vars)
{
    // Clear the previous image from the window
    mlx_clear_window(vars->mlx, vars->win);

    // Update the position of the image to follow the cursor
    vars->x = x - vars->img_width / 2;
    vars->y = y - vars->img_height / 2;

    // Draw the image at the new position
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
    return (0);
}

int main(void)
{
    t_vars vars;

    // Initialize the MLX and create a window
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 800, 600, "Move Image");

    // Load an XPM image (you can use your own XPM file here)
    vars.img = mlx_xpm_file_to_image(vars.mlx, "test2.xpm", &vars.img_width, &vars.img_height);

    // Set the initial position of the image
    vars.x = 100;
    vars.y = 100;

    // Draw the image at the initial position
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, vars.x, vars.y);

    // Register the key hook to handle key press events
    mlx_key_hook(vars.win, (int(*)())key_hook, &vars);
    mlx_hook(vars.win, 6, 1L<<6, (int(*)())mouse_hook, &vars);

    // Start the event loop
    mlx_loop(vars.mlx);

    return (0);
}