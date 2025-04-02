/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:30:15 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/02 12:02:58 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractl.h"

int	input_check(int ac, char **av)
{
	if ((ac < 2) || (ac > 4) || (ac == 3))
	{
		putstr_clr("Give Proper inputs dude!!!", 1, RED);
		putstr_clr("valid1: ./fractl <mandelbrot>", 1, BLUE);
		putstr_clr("valid2: ./fractl <julia>", 1, BLUE);
		exit(0);
	}
	else if ((ac > 1) && !ft_strcmp(av[1], "mandelbrot") && (ac == 2))
	{
		print_mandel_instr();
		return (1);
	}
	else if ((ac > 1) && !ft_strcmp(av[1], "julia") && (ac == 2))
	{
		print_julia_instr();
		return (2);
	}
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_fractal	fract;
	int			check;

	check = input_check(ac, av);
	fract.name = av[1];
	initialization(&fract);
	draw(&fract, -1, -1, '1');
	mlx_loop(fract.window.mlx_conn);
	return (0);
}
