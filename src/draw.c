/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:26:46 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/02 14:31:39 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractl.h"

void	switch_julia_constant(int key, t_fractal *fract)
{
	static t_axis	c_values[] = {{-0.7, 0.27015}, {0.285, 0.01}, {-0.8, 0.156},
	{0.355, 0.355}, {-0.70176, 0.3842}};
	static int		current_index = 0;

	if (key == XK_F5)
		current_index = (current_index + 1) % 5;
	else if (key == XK_F6)
		current_index = (current_index - 1 + 5) % 5;
	fract->c = c_values[current_index];
	if (!ft_strcmp(fract->name, "julia"))
		putstr_clr("JULIA changed", 1, VIOLET);
}

void	draw(t_fractal *fract, int x, int y, char c)
{
	char	iter_str[50];

	ft_strncpy(iter_str, "iterations :", 50);
	if (c == '1')
	{
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x < WIDTH)
				draw_pixel(x, y, fract);
		}
		mlx_put_image_to_window(fract->window.mlx_conn, fract->window.mlx_win,
			fract->image.image_ptr, 0, 0);
		ft_putnbr_str(fract->iterations, iter_str + 11, 0);
		mlx_string_put(fract->window.mlx_conn, fract->window.mlx_win, 10, 10,
			0xFFD700, iter_str);
	}
}

void	figure(t_axis *z, t_axis *c, t_fractal *fract)
{
	if (!ft_strcmp((*fract).name, "julia"))
	{
		c->x = fract->c.x;
		c->y = fract->c.y;
	}
	else if (!ft_strcmp((*fract).name, "mandelbrot"))
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	get_color(int x, int y, t_fractal *fract, int i)
{
	int	color;
	int	num;

	num = (i % 256) << 16 | ((i * 3) % 256) << 8 | ((i * 9) % 256);
	color = mlx_get_color_value(fract->window.mlx_conn, num);
	*(unsigned int *)(fract->image.pixels + (y * fract->image.line_len + x
				* (fract->image.bpp / 8))) = color;
}

void	draw_pixel(int x, int y, t_fractal *fract)
{
	t_axis	z;
	t_axis	c;
	int		i;

	i = 0;
	z.x = (scale_axis(x, 'x') * fract->zoom) + fract->axis.x;
	z.y = (scale_axis(y, 'y') * fract->zoom) + fract->axis.y;
	figure(&z, &c, fract);
	while (i < fract->iterations)
	{
		z = math_axis(math_axis(z, z, '^'), c, '+');
		if (math_axis(z, z, 'e').x > fract->esc_val)
		{
			get_color(x, y, fract, i);
			return ;
		}
		i++;
	}
	get_color(x, y, fract, i);
}
