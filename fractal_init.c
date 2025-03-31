/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:51:37 by gkamanur          #+#    #+#             */
/*   Updated: 2025/03/31 16:59:51 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractl.h"

int	handle_keys(int keys, t_fractal *fract)
{
	if (keys == XK_Escape)
		free_exit(fract);
	else if (keys == XK_Left)
		fract->axis.x = fract->axis.x + (0.5 * fract->zoom);
	else if (keys == XK_Right)
		fract->axis.x = fract->axis.x - (0.5 * fract->zoom);
	else if (keys == XK_Up)
		fract->axis.y = fract->axis.y - (0.5 * fract->zoom);
	else if (keys == XK_Down)
		fract->axis.y = fract->axis.y + (0.5 * fract->zoom);
	else if (keys == XK_F1)
		fract->iterations = fract->iterations + 10;
	else if (keys == XK_F2)
		fract->iterations = fract->iterations - 10;
	else if (keys == XK_F3)
		fract->zoom = fract->zoom * 0.9;
	else if (keys == XK_F4)
		fract->zoom = fract->zoom / 0.9;
	draw(fract, -1, -1, '1');
	return (0);
}
int handle_mouse(int button, int x, int y, t_fractal *fract)
{
    if (button == Button4)  // Scroll up (Zoom in)
        fract->zoom *= 0.9;
    else if (button == Button5)  // Scroll down (Zoom out)
        fract->zoom /= 0.9;

    draw(fract, -1, -1, '1');  // Redraw fractal after zooming
    return (0);
}
void	initialization(t_fractal *fract)
{
	if (!fract)
	{
        putstr_fd("Error: fract structure is NULL\n", 2);
        exit(1);
    }
	fract->window.mlx_conn = mlx_init();
	fract->window.mlx_win = mlx_new_window(fract->window.mlx_conn, WIDTH, HEIGHT, fract->name);
	fract->image.image_ptr = mlx_new_image(fract->window.mlx_conn, WIDTH, HEIGHT);
	fract->image.pixels = mlx_get_data_addr(fract->image.image_ptr,
			&fract->image.bpp, &fract->image.line_len, &fract->image.endian);
	mlx_hook(fract->window.mlx_win, KeyPress, KeyPressMask, handle_keys, fract);
	mlx_hook(fract->window.mlx_win, ButtonPress, ButtonPressMask, handle_mouse, fract);
	mlx_hook(fract->window.mlx_win, DestroyNotify, StructureNotifyMask, free_exit, fract);
	fract->iterations = 252;
	fract->esc_val = 4;
	fract->axis.x = 0.0;
	fract->axis.y = 0.0;
	fract->zoom = 1.0;
}
/*
void	initialization(t_fractal *fract)
{
	if (!fract)
	{
        putstr_fd("Error: fract structure is NULL\n", 2);
        exit(1);
    }
	fract->window.mlx_conn = mlx_init();
	if (!fract->window.mlx_conn)
    {
        putstr_fd("Error: Failed to initialize MiniLibX\n", 2);
        free_exit(fract);
    }
	fract->window.mlx_win = mlx_new_window(fract->window.mlx_conn, WIDTH, HEIGHT, fract->name);
	if (!fract->window.mlx_win)
    {
        putstr_fd("Error: Failed to create window\n", 2);
        free_exit(fract);
    }
	fract->image.image_ptr = mlx_new_image(fract->window.mlx_conn, WIDTH, HEIGHT);
	if (!fract->image.image_ptr)
    {
        putstr_fd("Error: Failed to create image\n", 2);
        free_exit(fract);
    }
	fract->image.pixels = mlx_get_data_addr(fract->image.image_ptr,
			&fract->image.bpp, &fract->image.line_len, &fract->image.endian);
	mlx_hook(fract->window.mlx_win, KeyPress, KeyPressMask, handle_keys, fract);
	mlx_hook(fract->window.mlx_win, ButtonPress, ButtonPressMask, handle_mouse, fract);
	mlx_hook(fract->window.mlx_win, DestroyNotify, StructureNotifyMask, free_exit, fract);
	fract->iterations = 252;
	fract->esc_val = 4;
	fract->axis.x = 0.0;
	fract->axis.y = 0.0;
	fract->zoom = 1.0;
}
*/
