/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:49:38 by gkamanur          #+#    #+#             */
/*   Updated: 2025/03/31 15:46:39 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractl.h"

double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    double result;

    result = (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
    return(result);
}
t_axis  math_axis(t_axis p1, t_axis p2, char c)
{
    t_axis res;

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
