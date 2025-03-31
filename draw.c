/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:26:46 by gkamanur          #+#    #+#             */
/*   Updated: 2025/03/31 17:11:46 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractl.h"

void draw(t_fractal *fract, int x, int y, char c)
{
    char iter_str[50] = "Iterations: ";
    if (c == '1')
    {
        while (++y < HEIGHT)
        {
            x = -1;
            while (++x < WIDTH)
                draw_pixel(x, y, fract);
        }
        mlx_put_image_to_window(fract->window.mlx_conn, fract->window.mlx_win, fract->image.image_ptr, 0, 0);
        ft_putnbr_str(fract->iterations, iter_str + 11);
        mlx_string_put(fract->window.mlx_conn, fract->window.mlx_win, 10, 10, DWHITE, iter_str);
    }
}
t_axis generate_random_point(void)
{
    t_axis point;

    double min_re = -1.5;
    double max_re = 1.5;
    double min_im = -1.5;
    double max_im = 1.5;

    // Generate random real and imaginary parts for the point
    point.x = (rand() / (double)RAND_MAX) * (max_re - min_re) + min_re; // Real part
    point.y = (rand() / (double)RAND_MAX) * (max_im - min_im) + min_im; // Imaginary part

    return point;
}
static void figure(t_axis *z, t_axis *c, t_fractal *fract)
{
    if (!ft_strcmp((*fract).name, "julia"))
    {
        c->x = generate_random_point().x;
        c->y = generate_random_point().y;
    }
    else if (!ft_strcmp((*fract).name, "mandelbrot"))
    {
        c->x = z->x;
        c->y = z->y;
    }
}
void my_pixel_put(t_fractal *data, int x, int y, int color)
{
    
}

static void draw_pixel(int x, int y, t_fractal *fract)
{
    t_axis z;
    t_axis c;
    int i;
    int color;
    
    i = 0;
    z.x = (scale(x, -2, +2, 0, WIDTH) * fract->zoom) + fract->axis.x;
    z.y = (scale(y, +2, -2, 0, WIDTH) * fract->zoom) + fract->axis.y;
    figure(&z, &c, fract);
    while (i < fract->iterations)
    {
        z = math_axis(math_axis(z, z, '^'), c, '+');
        if (math_axis(z, z, 'e').x > fract->esc_val)
        {
            color = scale(i, DBLACK, DWHITE, 0, fract->iterations);
            //my_pixel_put(fract, x, y, color);
            *(unsigned int *)(fract->image.pixels + (y * fract->image.line_len + x * (fract->image.bpp / 8))) = color;

            return ;
        }
        i++;
    }
    //my_pixel_put(fract, x, y, DWHITE);
    *(unsigned int *)(fract->image.pixels + (y * fract->image.line_len + x * (fract->image.bpp / 8))) = DWHITE;

}


