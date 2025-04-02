/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:51:37 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/02 14:46:44 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractl.h"

int	handle_keys(int keys, t_fractal *fract)
{
	if (!fract)
		return (0);
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
	else if (keys == XK_F5 || keys == XK_F6)
		switch_julia_constant(keys, fract);
	draw(fract, -1, -1, '1');
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *fract)
{
	if (!fract)
		return (0);
	(void)x;
	(void)y;
	if (button == Button4)
		fract->zoom *= 0.9;
	else if (button == Button5)
		fract->zoom /= 0.9;
	draw(fract, -1, -1, '1');
	return (0);
}

int	free_exit(t_fractal *fract)
{
	if (!fract)
	{
		putstr_clr("error in fract", 2, FILLED_RED);
		exit(-1);
	}
	if (fract->image.image_ptr)
		mlx_destroy_image(fract->window.mlx_conn, fract->image.image_ptr);
	if (fract->window.mlx_win)
		mlx_destroy_window(fract->window.mlx_conn, fract->window.mlx_win);
	if (fract->window.mlx_conn)
	{
		mlx_destroy_display(fract->window.mlx_conn);
		free(fract->window.mlx_conn);
	}
	putstr_clr("Program exits successfully.", 1, FILLED_DARK_INDIGO);
	exit(0);
}

void	init_values(t_fractal *fract)
{
	fract->iterations = 252;
	fract->esc_val = 4;
	fract->axis.x = 0;
	fract->axis.y = 0;
	fract->c.x = -0.70176;
	fract->c.y = -0.3842;
	fract->zoom = 1;
}

void	initialization(t_fractal *fract)
{
	if (!fract)
		free_exit(fract);
	fract->window.mlx_conn = mlx_init();
	if (!fract->window.mlx_conn)
		free_exit(fract);
	fract->window.mlx_win = mlx_new_window(fract->window.mlx_conn, WIDTH,
			HEIGHT, fract->name);
	if (!fract->window.mlx_win)
		free_exit(fract);
	fract->image.image_ptr = mlx_new_image(fract->window.mlx_conn, WIDTH,
			HEIGHT);
	if (!fract->image.image_ptr)
		free_exit(fract);
	fract->image.pixels = mlx_get_data_addr(fract->image.image_ptr,
			&fract->image.bpp, &fract->image.line_len, &fract->image.endian);
	mlx_hook(fract->window.mlx_win, KeyPress, KeyPressMask, handle_keys, fract);
	mlx_hook(fract->window.mlx_win, ButtonPress, ButtonPressMask, handle_mouse,
		fract);
	mlx_hook(fract->window.mlx_win, DestroyNotify, StructureNotifyMask,
		free_exit, fract);
	init_values(fract);
}
