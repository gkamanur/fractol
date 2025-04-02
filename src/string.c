/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:23:49 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/02 11:54:20 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractl.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	putstr_clr(char *str, int fd, char *clr)
{
	putstr_fd(clr, fd);
	putstr_fd(str, fd);
	putstr_fd(RESET "\n", fd);
}

void	print_mandel_instr(void)
{
	putstr_clr("⬆️  - to move up on axis", 1, LIGHT_VIOLET);
	putstr_clr("⬇️  - to move down on axis", 1, LIGHT_YELLOW);
	putstr_clr("⬅️  - to move left on axis", 1, LIGHT_VIOLET);
	putstr_clr("➡️  - to move right on axis", 1, LIGHT_YELLOW);
	putstr_clr("F1 - Iterations + 10", 1, LIGHT_VIOLET);
	putstr_clr("F2 - Iterations - 10", 1, LIGHT_YELLOW);
	putstr_clr("F3 - zoomIn", 1, LIGHT_VIOLET);
	putstr_clr("F4 - zoomOut", 1, LIGHT_YELLOW);
	putstr_clr("ESC - close", 1, LIGHT_VIOLET);
}

void	print_julia_instr(void)
{
	putstr_clr("⬆️  - to move up on axis", 1, LIGHT_VIOLET);
	putstr_clr("⬇️  - to move down on axis", 1, LIGHT_YELLOW);
	putstr_clr("⬅️  - to move left on axis", 1, LIGHT_VIOLET);
	putstr_clr("➡️  - to move right on axis", 1, LIGHT_YELLOW);
	putstr_clr("F1 - Iterations + 10", 1, LIGHT_VIOLET);
	putstr_clr("F2 - Iterations - 10", 1, LIGHT_YELLOW);
	putstr_clr("F3 - zoomIn", 1, LIGHT_VIOLET);
	putstr_clr("F4 - zoomOut", 1, LIGHT_YELLOW);
	putstr_clr("F5 - change +", 1, LIGHT_VIOLET);
	putstr_clr("F6 - change -", 1, LIGHT_YELLOW);
	putstr_clr("ESC - close", 1, LIGHT_VIOLET);
}
