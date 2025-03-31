/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:45:43 by gkamanur          #+#    #+#             */
/*   Updated: 2025/03/31 17:01:43 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTL_H
#define FRACTL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <time.h>
#include "colors.h"
#define WIDTH 800
#define HEIGHT 800

// #define LEFT 65361
// #define RIGHT 65363
// #define UP 65362
// #define DOWN 65364
// #define ESC 65307
// #define F1 65470
// #define F2 65470

#define DBLACK 0
#define DWHITE 16777215
#define DRED 16711680
#define DGREEN 65280
#define DBLUE 255
#define DYELLOW 16776960
#define DCYAN 65535
#define DMAGENTA 16711935
// #define GRAY 8421504
// #define LIGHT_GRAY 12632256
// #define DARK_GRAY 4210752
// #define ORANGE 16753920
// #define PINK 16761035
// #define PURPLE 8388736
// #define BROWN 10824234
// #define GOLD 16766720
// #define SILVER 12632256
// #define NAVY 128
// #define TEAL 32896
// #define OLIVE 8421376


typedef struct s_axis
{
    double x;
    double y;
}   t_axis;

typedef struct s_image
{
    void *image_ptr;
    char *pixels;
    int bpp;
    int endian;
    int line_len;
    
}   t_image;

typedef struct s_win
{
    void *mlx_conn;
    void *mlx_win;
} t_win;

typedef struct s_fractal
{
    char *name;
    t_win window;
    t_image image;
    t_axis axis;
    double esc_val;
    int iterations;
    double zoom;
} t_fractal;

int ft_strcmp(char *s1, char *s2);
void putstr_fd(char *str, int fd);
double ft_atodbl(const char *str);
void	ft_putnbr_str(int n, char *str);

int free_exit(t_fractal *fract);

void	initialization(t_fractal *fract);

t_axis  math_axis(t_axis p1, t_axis p2, char c);
double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);

void draw(t_fractal *fract, int x, int y, char c);
t_axis generate_random_point(void);
static void figure(t_axis *z, t_axis *c, t_fractal *fract);
static void my_pixel_put(t_fractal *data, int x, int y, int color);
static void draw_pixel(int x, int y, t_fractal *fract);
#endif