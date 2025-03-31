/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:30:15 by gkamanur          #+#    #+#             */
/*   Updated: 2025/03/31 14:54:03 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractl.h"

int	input_check(int ac, char **av)
{
	if ((ac < 2) || (ac > 4) || (ac == 3))
	{
        putstr_fd(RED, 1);
        putstr_fd("Give Proper inputs dude!!!", 1);
        putstr_fd(RESET "\n", 1);
        putstr_fd(BLUE, 1);
        putstr_fd("valid1: ./fractl <mandelbrot>", 1);
        putstr_fd(RESET "\n", 1);
        putstr_fd(BLUE, 1);
        putstr_fd("valid2: ./fractl <julia> <double> <double>", 1);
        putstr_fd(RESET "\n", 1);
		return (-1);
	}
	else if (!ft_strcmp(av[1], "mandelbrot") && (ac == 2))
		return (1);
	else if (!ft_strcmp(av[1], "julia") && (ac == 4))
		return (2);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_fractal fract;
	t_axis julia;

	if (input_check(ac, av) == 2)
	{
		julia.x = ft_atodbl(av[2]);
		julia.y = ft_atodbl(av[3]);
	}
    fract.name = av[1];
	initialization(&fract);
	draw(&fract, -1, -1, '1');
	mlx_loop(fract.window.mlx_conn);
	return (0);
}