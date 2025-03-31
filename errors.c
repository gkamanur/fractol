/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:18:00 by gkamanur          #+#    #+#             */
/*   Updated: 2025/03/31 17:14:22 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractl.h"

int free_exit(t_fractal *fract)
{
    // if (message)
    // {
    //     putstr_fd (message, 2);
    //     write (1, "\n", 2);
    // }
    if (fract->image.image_ptr)
        mlx_destroy_image(fract->window.mlx_conn,fract->image.image_ptr);
    if (fract->window.mlx_win)
        mlx_destroy_image(fract->window.mlx_conn,fract->window.mlx_win);
    if (fract->window.mlx_conn)
    {
        mlx_destroy_display(fract->window.mlx_conn);
        free(fract->window.mlx_conn);
    }
    free(fract);
    exit(0);
    return (0);
}

/*
void close_display(t_fractal *data)
{
    if (data->window.mlx_conn)
    {
        mlx_destroy_display(data->window.mlx_conn);
        free(data->window.mlx_conn);
    }
}

void init_errors(t_fractal *fract)
{
    if (!fract->window.mlx_conn)
    {
        putstr_fd("Malloc Error: MLX connection failed\n", 2);
        exit(1);
    }
    else if (!fract->window.mlx_win)
    {
        putstr_fd("Malloc Error: Window creation failed\n", 2);
        close_display(fract);
        exit(1);
    }
    else if (!fract->image.image_ptr)
    {
        putstr_fd("Malloc Error: Image creation failed\n", 2);
        mlx_destroy_window(fract->window.mlx_conn, fract->window.mlx_win);
        close_display(fract);
        exit(1);
    }
}

int close_window(t_fractal *fract)
{
    if (fract->image.image_ptr)
        mlx_destroy_image(fract->window.mlx_conn, fract->image.image_ptr);
    if (fract->window.mlx_win)
        mlx_destroy_window(fract->window.mlx_conn, fract->window.mlx_win);
    if (fract->window.mlx_conn)
    {
        mlx_destroy_display(fract->window.mlx_conn);
        free(fract->window.mlx_conn);
    }
    exit(0);
    return (0);
}
    */
