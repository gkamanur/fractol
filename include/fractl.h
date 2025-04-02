/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:45:43 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/02 14:37:31 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTL_H
# define FRACTL_H
# include "../minilibx-linux/mlx.h"
# include "colors.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 800
# define HEIGHT 800

typedef struct s_axis
{
	double	x;
	double	y;
}			t_axis;

typedef struct s_image
{
	void	*image_ptr;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;

}			t_image;

typedef struct s_win
{
	void	*mlx_conn;
	void	*mlx_win;
}			t_win;

typedef struct s_fractal
{
	char	*name;
	t_axis	axis;
	t_axis	c;
	t_win	window;
	t_image	image;
	double	esc_val;
	int		iterations;
	double	zoom;
}			t_fractal;

int			ft_strcmp(const char *s1, const char *s2);
void		putstr_fd(char *str, int fd);
void		ft_putnbr_str(int n, char *str, int i);
void		putstr_clr(char *str, int fd, char *clr);
char		*ft_strncpy(char *dest, const char *src, size_t n);
void		print_julia_instr(void);
void		print_mandel_instr(void);
int			free_exit(t_fractal *fract);
void		initialization(t_fractal *fract);
void		switch_julia_constant(int key, t_fractal *fract);
t_axis		math_axis(t_axis p1, t_axis p2, char c);
double		scale_axis(double axis, char c);
void		draw(t_fractal *fract, int x, int y, char c);
void		draw_pixel(int x, int y, t_fractal *fract);
#endif