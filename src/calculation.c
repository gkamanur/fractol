/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:49:38 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/02 11:59:35 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractl.h"

double	get_scale_factor(double new_min, double new_max, double old_min,
		double old_max)
{
	return ((new_max - new_min) / (old_max - old_min));
}

double	get_axis_scale_factor(char c)
{
	if (c == 'x')
		return (get_scale_factor(-2, 2, 0, WIDTH));
	else if (c == 'y')
		return (get_scale_factor(2, -2, 0, HEIGHT));
	return (1);
}

double	scale_axis(double axis, char c)
{
	double	new_min;
	double	scale_factor;

	new_min = 0.0;
	if (c == 'x')
		new_min = -2;
	if (c == 'y')
		new_min = 2;
	scale_factor = get_axis_scale_factor(c);
	return (new_min + scale_factor * axis);
}

t_axis	math_axis(t_axis p1, t_axis p2, char c)
{
	t_axis	res;

	res.x = 0;
	res.y = 0;
	if (c == '+')
	{
		res.x = p1.x + p2.x;
		res.y = p1.y + p2.y;
	}
	else if (c == '^')
	{
		res.x = (p1.x * p1.x) - (p1.y * p1.y);
		res.y = 2 * p1.x * p1.y;
	}
	else if (c == 'e')
	{
		res.x = (p1.x * p1.x) + (p1.y * p1.y);
		res.y = 0;
	}
	return (res);
}
